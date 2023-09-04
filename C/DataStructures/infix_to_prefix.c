/*
 * File: infix_to_prefix.c
 * Author: Siddhartha Chandra
 * Email: siddhartha_chandra@spit.ac.in
 * Created: September 1, 2023
 * Description: This program converts an infix expression to prefix (polish
 * notation)
 */

#include <string.h>

#include "helper_functions.c"
#include "stack.c"

// precedence map
// 1-> highest ; 4 -> lowest
// ^ -> 1
// *, / -> 2
// +, - -> 3
// others -> 4

char *infixToPrefix(char *infix)
{
	int length = strlen(infix);
	char *prefix = (char *)malloc((length + 1) * sizeof(char)); // +1 for the null terminator
	int i, j = 0;

	// Reverse the infix expression
	char *reversedInfix = (char *)malloc((length + 1) * sizeof(char));
	for (i = length - 1; i >= 0; i--)
	{
		if (infix[i] == '(')
			reversedInfix[j++] = ')';
		else if (infix[i] == ')')
			reversedInfix[j++] = '(';
		else
			reversedInfix[j++] = infix[i];
	}
	reversedInfix[j] = '\0';

	struct Stack *stack = initialize_stack(length);
	for (i = 0, j = 0; i < length; i++)
	{
		if (is_operator(reversedInfix[i]))
		{
			while (!isEmpty(stack) && is_higher_or_equal(reversedInfix[i], stack->array[stack->top]))
			{
				prefix[j++] = stack->array[stack->top];
				stack->top--;
			}
			stack->top++;
			stack->array[stack->top] = reversedInfix[i];
		}
		else if (reversedInfix[i] == '(')
		{
			stack->top++;
			stack->array[stack->top] = reversedInfix[i];
		}
		else if (reversedInfix[i] == ')')
		{
			while (!isEmpty(stack) && stack->array[stack->top] != '(')
			{
				prefix[j++] = stack->array[stack->top];
				stack->top--;
			}
			if (!isEmpty(stack) && stack->array[stack->top] == '(')
				stack->top--;
		}
		else
		{
			prefix[j++] = reversedInfix[i];
		}
	}

	// Pop any remaining operators from the stack
	while (!isEmpty(stack))
	{
		prefix[j++] = stack->array[stack->top];
		stack->top--;
	}

	prefix[j] = '\0';
	free(reversedInfix);
	free(stack->array);
	free(stack);

	// Reverse the prefix expression to get the final result
	length = strlen(prefix);
	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		char temp = prefix[i];
		prefix[i] = prefix[j];
		prefix[j] = temp;
	}
	return prefix;
}

int main()
{
	char infix[100];
	printf("Enter the Infix Expression: ");
	scanf("%[^\n]", infix);
	char *prefix = infixToPrefix(infix);
	printf("Prefix Expression: %s\n", prefix);
	free(prefix);
	return 0;
}