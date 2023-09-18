// In this linked list implementation the head points to the node that stores
// the first element of the linked list

// Create a Linked List ADT using the Struct 'Node'.
// The Linked List should support all operations that are listed as functions in
// this file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

// create a LinkedList node with 'data'
Node *create_node(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
}
int size = 0;
// pos=-1 indicates insert at end
// pos=0 indicates add at beginning
// This creates a new LinkedList node and inserts it at position 'pos' in the
// current linked list originating from head
void insert_at_pos(Node *head, int pos, int data) {
  size++;
  if (pos == 0) {
    Node *newNode = create_node(data);
    newNode->next = head;
    head = newNode;
    return;
  } else if (pos == -1 || pos == (size - 1)) {
    Node *newNode = create_node(data);
    head->next = newNode;
  } else if (pos > 0 && pos < (size - 1)) {
    Node *newNode = create_node(data);
    while (pos--) {
      head = head->next;
    }
    newNode->next = head->next;
    head->next = newNode;

  } else {
    printf("\n> Invalid POS!\n");
    size--;
  }
}

// pos=-1 indicates delete last node
// pos=0 indicates delete first node
// This deletes the LinkedList node at position 'pos' in the current linked list
// originating from head
void delete_at_pos(Node *head, int pos) {}

// delete linkedlist node with first occurrence of given value from linked list
// originating from 'head'
void delete_by_value(Node *head, int value) {}

// gets the node at position 'pos' in linkedlist originating from 'head'
// return 'null' if no node found along with informative message
Node *get_node_at_pos(Node *head, int pos) {}

// Return the node with the first occurrence of value
// return 'null' if no node found along with informative message
Node *find_first(Node *head, int value) {}

// display entire linked list, starting from head, in a well-formatted way
void display(Node *head) {
  printf("\nCurrent LinkedList: ");
  while (head->next != NULL) {
    printf("\n> Data: %d", head->data);
    head = head->next;
  }
}

// deallocate the memory being used by the entire linkedlist, starting from head
void free_linkedlist(Node *head) {}

// reverse a linkedlist - reverse a given linked list
Node *reverse(Node *head) {}

void main() {
  Node *ll = create_node(1);
  
}