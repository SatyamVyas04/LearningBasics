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
	return node;
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
	if (head == NULL)
	{
		printf("\n> Linked List is already empty! \n");
		return;
	}
	if (pos == 0)
	{
		*head = (*head)->next;
		return;
	}
	else if (pos == -1 || pos == size - 1)
	{
		Node *templl = *head;
		while (templl->next->next != NULL)
		{
			templl = templl->next;
		}
		templl->next = NULL;
		return;
	}
	else if (pos > 0 && pos < size - 1)
	{
		Node *templl = *head;
		while (--pos)
		{
			templl = templl->next;
		}
		Node *after_toberemoved = templl->next->next;
		templl->next = after_toberemoved;
		return;
	}
	else
	{
		printf("\n> Invalid POS!\n");
		return;
	}
}

// Delete by Value/Data of the Node
void delete_by_value(Node **head, int value)
{
	if (head == NULL)
	{
		printf("\n> Linked List is already empty! \n");
		return;
	}

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

// Get Node at a certain Position
Node *get_node_at_pos(Node **head, int pos)
{
	if (head == NULL)
	{
		printf("\n> Linked List is empty! \n");
		return NULL;
	}
	Node *templl = *head;
	if (pos == 0)
	{
		return templl;
	}
	else if (pos == -1 || pos == size - 1)
	{
		while (templl->next != NULL)
		{
			templl = templl->next;
		}
		return templl;
	}
	else if (pos > 0 && pos < size - 1)
	{
		while (pos--)
		{
			templl = templl->next;
		}
		return templl;
	}
	else
	{
		printf("\n> Invalid POS!\n");
		return NULL;
	}
}

// Return First Occurence of a Node
Node *find_first(Node **head, int value)
{
	if (head == NULL)
	{
		printf("\n> Linked List is empty! \n");
		return NULL;
	}
	Node *templl = *head;
	// Tail Check
	if (templl->data == value)
	{
		return templl;
	}

	// Check Mid
	while (templl->next != NULL)
	{
		if (templl->data == value)
		{
			return templl;
		}
		else
		{
			templl = templl->next;
		}
	}

	// Head Check
	if (templl->data == value)
	{
		return templl;
	}
	return NULL;
}

// Display Linked List
void display(Node *head)
{
	if (head == NULL)
	{
		printf("\n> Linked List is empty! \n");
		return;
	}
	printf("\nLinked List: head ->");
	while (head->next != NULL)
	{
		printf(" [%d] ->", head->data);
		head = head->next;
	}
	printf(" [%d] -> tail\n", head->data);
}

// Deallocate Linked List Memory
void free_linkedlist(Node *head)
{
	Node *tmp;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

// Reverse a Linked List
Node *reverse(Node *head)
{
	Node *prevNode = NULL;
	Node *current = head;
	Node *nextNode = NULL;
	while (current)
	{
		nextNode = current->next;
		current->next = prevNode;
		prevNode = current;
		current = nextNode;
	}
	return prevNode;
}

// void main()
// {
// 	Node *ll = create_node(2);
// 	insert_at_pos(&ll, 0, 1);  // Insert at 0
// 	insert_at_pos(&ll, -1, 3); // Insert at -1
// 	insert_at_pos(&ll, 3, 4);  // Insert at a random POS
// 	insert_at_pos(&ll, -1, 5); // Insert at -1
// 	// insert_at_pos(&ll, -2, 10); // Error Check

// 	/*
// 		delete_at_pos(&ll, 1);	  // Should delete POS 1 i.e 2;
// 		display(ll);			  // Seeing the changes in LL
// 		insert_at_pos(&ll, 1, 2); // Putting back 2 to test again

// 		delete_at_pos(&ll, 0);	  // Should delete POS 0 i.e 1;
// 		display(ll);			  // Seeing the changes in LL
// 		insert_at_pos(&ll, 0, 1); // Putting back 2 to test again

// 		delete_at_pos(&ll, 4);	  // Should delete POS 4 i.e 5;
// 		display(ll);			  // Seeing the changes in LL
// 		insert_at_pos(&ll, 4, 5); // Putting back 2 to test again

// 		delete_by_value(&ll, 1); // Value at Tail
// 		delete_by_value(&ll, 2); // Value in Between
// 		delete_by_value(&ll, 5); // Value at Head
// 		delete_by_value(&ll, 6); // Invalid Test

// 		Node *node = get_node_at_pos(&ll, 0);
// 		node = get_node_at_pos(&ll, 1);
// 		node = get_node_at_pos(&ll, 2);
// 		node = get_node_at_pos(&ll, 3);
// 		node = get_node_at_pos(&ll, 4);
// 		node = get_node_at_pos(&ll, 5);
// 		node = get_node_at_pos(&ll, -1);
// 		if (node != NULL)
// 		{
// 			printf("\n> Node: %d", node->data);
// 		}
// 		else
// 		{
// 			printf("\n> Invalid POS");
// 		}

// 		Node *node = find_first(&ll, 1);
// 		node = find_first(&ll, 2);
// 		node = find_first(&ll, 3);
// 		node = find_first(&ll, 4);
// 		node = find_first(&ll, 5);
// 		node = find_first(&ll, -1);
// 		if (node != NULL)
// 		{
// 			display(node);
// 		}
// 		else
// 		{
// 			printf("\n> Invalid POS");
// 		}

// 		display(ll);
// 		ll = reverse(ll);
// 	*/
// 	display(ll);
// }
