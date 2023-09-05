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
	char *ans = (char *)malloc((length + 1) * sizeof(char)); // extra for null
	int i, j = 0;

	// Reversal
	char *revInfix = (char *)malloc((length + 1) * sizeof(char));
	for (i = length - 1; i >= 0; i--)
	{
		if (infix[i] == '(')
			revInfix[j++] = ')';
		else if (infix[i] == ')')
			revInfix[j++] = '(';
		else
			revInfix[j++] = infix[i];
	}
	revInfix[j] = '\0';

	struct Stack *stack = initialize_stack(length);
	for (i = 0, j = 0; i < length; i++)
	{
		if (is_operator(revInfix[i]))
		{
			// It will pop from stack till a higher precendence operator is found
			while (!isEmpty(stack) && is_higher_or_equal(stack->array[stack->top], revInfix[i]))
			{
				ans[j++] = stack->array[stack->top];
				stack->top--;
			}
			stack->top++;
			stack->array[stack->top] = revInfix[i];
		}
		else if (revInfix[i] == '(')
		{
			stack->top++;
			stack->array[stack->top] = revInfix[i];
		}
		else if (revInfix[i] == ')')
		{
			while (!isEmpty(stack) && stack->array[stack->top] != '(')
			{
				ans[j++] = stack->array[stack->top];
				stack->top--;
			}
			if (!isEmpty(stack) && stack->array[stack->top] == '(')
				stack->top--;
		}
		else
		{
			ans[j++] = revInfix[i];
		}
	}

	// Pop other remaining operators
	while (!isEmpty(stack))
	{
		ans[j++] = stack->array[stack->top];
		stack->top--;
	}

	ans[j] = '\0';

	// Freeing allocated space
	free(revInfix);
	free(stack->array);
	free(stack);

	// Reverse again
	length = strlen(ans);
	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		char temp = ans[i];
		ans[i] = ans[j];
		ans[j] = temp;
	}
	return ans;
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
