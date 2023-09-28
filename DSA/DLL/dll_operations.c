/*
 * File: dll_operations.c
 * Author: Siddhartha Chandra
 * Email: siddhartha_chandra@spit.ac.in
 * Created: September 24, 2023
 *
 * Description: This implements ADT for
 * storing a DLL and performing operations
 * on it. Use dummy nodes - header and
 * trailer, in your implementation
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
} Node;
int size = 0;

Node *create_node(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->val = val;
    size++;
    return node;
}

// Insert at or after a Position in Linked List
void insert_at_pos(Node **header, Node **trailer, int pos, bool is_after, int data) {
    if (pos == 0) {
        Node *newNode = create_node(data);
        newNode->next = (*header);
        newNode->prev = NULL;
        (*header)->prev = newNode;
        *header = newNode;

    } else if (pos == -1 || ((pos == size) && is_after)) {
        Node *newNode = create_node(data);
        newNode->prev = (*trailer);
        newNode->next = NULL;
        (*trailer)->next = newNode;
        (*trailer) = newNode;

    } else if (pos > 0 && pos <= size - 1) {
        if (!is_after) {
            pos--;
        }

        Node *newNode = create_node(data);
        Node *templl = *header;
        while (pos != 1) {
            templl = templl->next;
            pos--;
        }
        Node *next_in_line = templl->next;
        templl->next = newNode;
        newNode->prev = templl;
        newNode->next = next_in_line;
        next_in_line->prev = newNode;

    } else {
        printf("\n> Invalid POS!\n");
    }
}

// Delete at Position in Linked List
void delete_at_pos(Node **header, Node **trailer, int pos) {
    if (header == NULL) {
        printf("\n> Linked List is already empty! \n");
        return;
    }
    if (pos == 0) {
        *header = (*header)->next;
        return;
    } else if (pos == -1 || pos == size - 1) {
        *trailer = (*trailer)->prev;
        return;
    } else if (pos > 0 && pos < size - 1) {
        Node *templl = *header;
        while (--pos) {
            templl = templl->next;
        }
        Node *after_toberemoved = templl->next->next;
        templl->next = after_toberemoved;
        after_toberemoved->prev = templl;
        return;
    } else {
        printf("\n> Invalid POS!\n");
        return;
    }
}

void reverse(Node **header) {
    Node *temp = NULL;
    Node *current = *header;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *header = temp->prev;
    } else {
        *header = current;
    }
}

// Swap 2 nodes in DLL
void swap(Node **header, Node **trailer, int pos_1, int pos_2) {
    if (*header == NULL || *trailer == NULL) {
        printf("\n> Linked List is empty! \n");
        return;
    }
    if (pos_1 < -1 || pos_2 < -1 || pos_1 >= size || pos_2 >= size) {
        printf("\n> Invalid positions!\n");
        return;
    }
    // Fixing -1 Indexing
    if (pos_1 == -1) {
        pos_1 = size - 1;
    }
    if (pos_2 == -1) {
        pos_2 = size - 1;
    }
    if (pos_1 == pos_2) {
        // No need to swap, positions are the same
        return;
    }
    // Ensure pos_1 <= pos_2
    if (pos_1 > pos_2) {
        int temp = pos_1;
        pos_1 = pos_2;
        pos_2 = temp;
    }

    Node *node1 = *header;
    Node *node2 = *header;

    if (pos_1 == 0 && pos_2 == size - 1) {
        Node *tail = *trailer;
        Node *head = *header;
        Node *nexttohead = head->next;
        Node *prevtotail = tail->prev;
        head->next = NULL;
        tail->prev = NULL;
        nexttohead->prev = tail;
        tail->next = nexttohead;
        prevtotail->next = head;
        head->prev = prevtotail;
        *header = tail;
        *trailer = head;
        return;
    }

    for (int i = 0; i < pos_1; i++) {
        node1 = node1->next;
    }
    for (int i = 0; i < pos_2; i++) {
        node2 = node2->next;
    }

    if (pos_2 - pos_1 == 1) {
        if (pos_1 == 0) {
            Node *next2 = node2->next;
            node2->prev = NULL;
            node2->next = node1;
            node1->prev = node2;
            node1->next = next2;
            next2->prev = node1;
            *header = node2;
            return;
        }
        if (pos_2 == size - 1) {
            Node *prev1 = node1->prev;
            prev1->next = node2;
            node2->prev = prev1;
            node2->next = node1;
            node1->prev = node2;
            node1->next = NULL;
            *trailer = node1;
            return;
        }
        Node *prev1 = node1->prev;
        Node *next2 = node2->next;
        prev1->next = node2;
        node2->prev = prev1;
        node2->next = node1;
        node1->prev = node2;
        node1->next = next2;
        next2->prev = node1;
        if (prev1 == NULL)
            *header = node2;
    } else {
        if (pos_1 == 0) {
            Node *next1 = node1->next;
            Node *prev2 = node2->prev;
            Node *next2 = node2->next;
            node2->prev = NULL;
            node2->next = next1;
            next1->prev = node2;
            prev2->next = node1;
            node1->prev = prev2;
            next2->prev = node1;
            node1->next = next2;
            *header = node2;
            return;
        }
        if (pos_2 == size - 1) {
            Node *prev1 = node1->prev;
            Node *next1 = node1->next;
            Node *prev2 = node2->prev;
            prev1->next = node2;
            node2->prev = prev1;
            node2->next = next1;
            next1->prev = node2;
            prev2->next = node1;
            node1->prev = prev2;
            node1->next = NULL;
            *trailer = node1;
            return;
        }
        Node *prev1 = node1->prev;
        Node *next1 = node1->next;
        Node *prev2 = node2->prev;
        Node *next2 = node2->next;
        prev1->next = node2;
        node2->prev = prev1;
        node2->next = next1;
        next1->prev = node2;
        prev2->next = node1;
        node1->prev = prev2;
        next2->prev = node1;
        node1->next = next2;
        if (prev1 == NULL)
            *header = node2;
    }
}

void display(Node *header, Node *trailer) {
    if (header == NULL) {
        printf("\n> Linked List is empty! \n");
        return;
    }
    printf("\nLinked List: (header) <->");
    while (header->next != NULL) {
        printf(" [%d] <->", header->val);
        header = header->next;
    }
    printf(" [%d] <-> (trailer)\n", header->val);
}

void main() {
    Node *header = create_node(1);
    Node *trailer = create_node(10);
    header->next = trailer;
    header->prev = header;
    insert_at_pos(&header, &trailer, 1, true, 4);
    insert_at_pos(&header, &trailer, 0, true, 0);
    insert_at_pos(&header, &trailer, -1, true, 11);
    insert_at_pos(&header, &trailer, 3, true, 5);
    insert_at_pos(&header, &trailer, 3, false, 3);
    display(header, trailer);
    printf("\n> Size: %d\n", size);
    // Working fine

    delete_at_pos(&header, &trailer, -1);
    display(header, trailer);
    // Working fine

    reverse(&header);
    display(header, trailer);
    // Working fine

    swap(&header, &trailer, 0, 1);
    display(header, trailer);
    swap(&header, &trailer, 0, 3);
    display(header, trailer);
    swap(&header, &trailer, 5, -1);
    display(header, trailer);
    swap(&header, &trailer, 2, -1);
    display(header, trailer);
    swap(&header, &trailer, 0, -1);
    display(header, trailer);
    // Working Fine
}