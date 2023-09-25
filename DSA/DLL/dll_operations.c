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

void reverse(Node *header, Node *trailer) {
    printf("This should reverse the doubly linked list");
}

// pos == 0 indicates start of the DLL
// pos == -1 indicates end of the DLL
// pos == n indicates intermediate node pos

// this swaps the 2 nodes in the DLL at positions pos_1 and pos_2
// please note, the nodes have to be swapped and not just values
void swap(Node *header, Node *trailer, int pos_1, int pos_2) {
    printf("This should swap the nodes in the DLL at pos_1 and pos_2");
}

void display(Node *header, Node *trailer) {
    if (header == NULL) {
        printf("\n> Linked List is empty! \n");
        return;
    }
    printf("\nLinked List: (header) <->");
    while (header != trailer) {
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
    // display(header, trailer);
    insert_at_pos(&header, &trailer, 1, true, 4);
    // display(header, trailer);
    insert_at_pos(&header, &trailer, 0, true, 0);
    // display(header, trailer);
    insert_at_pos(&header, &trailer, -1, true, 11);
    // display(header, trailer);
    insert_at_pos(&header, &trailer, 3, true, 5);
    // display(header, trailer);
    insert_at_pos(&header, &trailer, 3, false, 3);
    display(header, trailer);
    // Working fine

    delete_at_pos(&header, &trailer, -1);
    display(header, trailer);
    // Working fine
}