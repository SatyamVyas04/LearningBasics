// Create a Linked List ADT using the Struct 'Node'.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;
int size = 0;

// Create Node
Node *create_node(int data)
{
	size++;
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
}

// Insert at Position in Linked List
void insert_at_pos(Node **head, int pos, int data)
{
	if (pos == 0)
	{
		Node *newNode = create_node(data);
		newNode->next = (*head);
		*head = newNode;
	}
	else if (pos == -1 || pos == size)
	{
		Node *newNode = create_node(data);
		Node *templl = *head;
		while (templl->next != NULL)
		{
			templl = templl->next;
		}
		templl->next = newNode;
	}
	else if (pos > 0 && pos <= size - 1)
	{
		Node *newNode = create_node(data);
		Node *templl = *head;
		while (pos != 1)
		{
			templl = templl->next;
			pos--;
		}
		Node *next_in_line = templl->next;
		templl->next = newNode;
		newNode->next = next_in_line;
	}
	else
	{
		printf("\n> Invalid POS!\n");
	}
}

// Delete at Position in Linked List
void delete_at_pos(Node **head, int pos)
{
	if (pos == 0)
	{
		*head = (*head)->next;
	}
	else if (pos == -1 || pos == size)
	{
		Node *templl = *head;
		while (templl->next->next != NULL)
		{
			templl = templl->next;
		}
		templl->next = NULL;
	}
	else if (pos > 0 && pos <= size - 1)
	{
		Node *templl = *head;
		while (pos != 1)
		{
			templl = templl->next;
			pos--;
		}
		Node *after_toberemoved = templl->next->next;
		templl->next = after_toberemoved;
	}
	else
	{
		printf("\n> Invalid POS!\n");
	}
}

// Delete by Value/Data of the Node
void delete_by_value(Node **head, int value)
{
	Node *templl = *head;
	Node *prevNode = *head;
	Node *nextNode = (*head)->next;
	// Check for Tail in LinkedList
	if (templl->data == value)
	{
		*head = (*head)->next;
		printf("\n> Removed %d\n", value);
	}
	else
	{
		while (templl->next != NULL)
		{
			if (templl->data == value)
			{
				prevNode->next = nextNode;
				printf("\n> Removed %d\n", value);
				return;
			}
			prevNode = templl;
			templl = templl->next;
			nextNode = templl->next;
		}
		// Check for Head
		if (templl->data == value)
		{
			prevNode->next = NULL;
			printf("\n> Removed %d\n", value);
			return;
		}
		else
		{
			printf("\n> Value not Found\n");
		}
	}
}

// gets the node at position 'pos' in linkedlist originating from 'head'
// return 'null' if no node found along with informative message
Node *get_node_at_pos(Node **head, int pos) {}

// Return the node with the first occurrence of value
// return 'null' if no node found along with informative message
Node *find_first(Node **head, int value) {}

// display entire linked list, starting from head, in a well-formatted way
void display(Node *head)
{
	printf("\nLinked List: tail ->");
	while (head->next != NULL)
	{
		printf(" [%d] ->", head->data);
		head = head->next;
	}
	printf(" [%d] -> head\n", head->data);
}

// deallocate the memory being used by the entire linkedlist, starting from head
void free_linkedlist(Node *head) {}

// reverse a linkedlist - reverse a given linked list
Node *reverse(Node *head) {}

void main()
{
	Node *ll = create_node(2);
	insert_at_pos(&ll, 0, 1);  // Insert at 0
	insert_at_pos(&ll, -1, 3); // Insert at -1
	insert_at_pos(&ll, 3, 4);  // Insert at a random POS
	insert_at_pos(&ll, -1, 5); // Insert at -1
	/*
		insert_at_pos(&ll, 6, 10); // Test Invalid
		display(ll);

		delete_at_pos(&ll, 1);	   // Should delete POS 1 i.e 2;
		display(ll);			   // Seeing the changes in LL
		insert_at_pos(&ll, 1, 2);  // Putting back 2 to test again
		display(ll);			   // Final Display
		delete_at_pos(&ll, 0);	   // Should delete POS 0 i.e 1;
		display(ll);			   // Seeing the changes in LL
		insert_at_pos(&ll, 0, 1);  // Putting back 2 to test again
		display(ll);			   // Final Display
		delete_at_pos(&ll, -1);	   // Should delete POS -1 i.e 5;
		display(ll);			   // Seeing the changes in LL
		insert_at_pos(&ll, -1, 5); // Putting back 2 to test again
		display(ll);			   // Final Display
		delete_at_pos(&ll, 6);	   // Error Check;

		delete_by_value(&ll, 1); // Value at Tail
		delete_by_value(&ll, 2); // Value in Between
		delete_by_value(&ll, 5); // Value at Head
		delete_by_value(&ll, 6); // Invalid Test
	*/

	display(ll);
}
