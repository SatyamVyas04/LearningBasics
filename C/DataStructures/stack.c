/*
 * File: stack.c
 * Author: Siddhartha Chandra
 * Email: siddhartha_chandra@spit.ac.in
 * Created: September 1, 2023
 * Description: This program implements a Stack ADT
 */

#include <stdio.h>
#include <stdlib.h>

// Build a Stack Abstract Data structure and perform operations on it
// Operations:
// 1. Push
// 2. Pop
// 3. Peek
// 4. isEmpty
// 5. isFull
// 6. display

struct Stack
{
	int top;
	unsigned size;
	char *array;
};

// 0 -> display
void display(struct Stack *stack)
{
	printf("> %c <--- Top of the Stack\n", stack->array[stack->top]);
	for (int i = stack->top - 1; i >= 0; i--)
	{
		printf("> %c\n", stack->array[i]);
	}
}

// 1 -> Initialize
struct Stack *initialize_stack(unsigned size)
{
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
	stack->size = size;
	stack->top = -1;
	stack->array = (char *)malloc(stack->size * sizeof(char));
	return stack;
}

// 2 -> isFull
int isEmpty(struct Stack *stack) { return stack->top == -1; }

// 3 -> isEmpty
int isFull(struct Stack *stack) { return stack->top == stack->size - 1; }

// 4 -> push
void push(struct Stack *stack, char item)
{
	if (isFull(stack))
	{
		return;
	}
	stack->top++;
	stack->array[stack->top] = item;
}

// 5 -> peek
char peek(struct Stack *stack)
{
	if (isEmpty(stack))
	{
		return 'x';
	}
	printf("> %c <--- Top of the Stack\n", stack->array[stack->top]);
	return stack->array[stack->top];
}

// 6 -> pop
char pop(struct Stack *stack)
{
	if (isEmpty(stack))
	{
		return 0;
	}
	char item;
	item = stack->array[stack->top];
	stack->top--;
	return item;
}

// void main()
// {
// 	struct Stack *s = initialize_stack(10);
// 	push(s, 'a');
// 	push(s, 'b');
// 	push(s, 'c');
// 	push(s, 'd');
// 	push(s, 'e');
// 	peek(s);
// 	display(s);
// 	pop(s);
// 	display(s);
// }