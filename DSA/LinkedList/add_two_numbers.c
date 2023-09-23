/*
You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

operand_1: 7 -> 2 -> 3 -> 3
operand_2: 5 -> 7 -> 4

result: 7 -> 8 -> 0 -> 7

*/

#include "linked_list.c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10

Node *add_two_numbers(Node *l1, Node *l2)
{
    int num1[SIZE];
    int num2[SIZE];
    int final[SIZE + 1];
    l1 = reverse(l1);
    l2 = reverse(l2);

    // Initialise with 0's
    for (int i = 0; i < SIZE; i++)
    {
        num1[i] = 0;
        num2[i] = 0;
        final[i] = 0;
    }
    final[-1] = 0;

    // Traverse Nodes to get all Digits
    int index = 0;
    Node *templl = l1;
    while (templl != NULL)
    {
        num1[index] = templl->data;
        templl = templl->next;
        index++;
    }
    index = 0;
    templl = l2;
    while (templl != NULL)
    {
        num2[index] = templl->data;
        templl = templl->next;
        index++;
    }

    // Reverting back our initial linked list
    l1 = reverse(l1);
    l2 = reverse(l2);

    // Displaying all digits
    printf("\n> NUM1 (reversed):");
    for (int i = 0; i < SIZE; i++)
    {
        printf(" %d ", num1[i]);
    }
    printf("\n> NUM2 (reversed):");
    for (int i = 0; i < SIZE; i++)
    {
        printf(" %d ", num2[i]);
    }

    // Adding the 2 numbers
    double sum = 0; 
    for (int i = 0; i < SIZE; i++) {
        sum += (num1[i] + num2[i]) * pow(10, i);
    }
    printf("\n> SUM: %.0lf\n", sum); 

    // Start ans node by adding ones digit
    Node *ans = create_node((int)(fmod(sum, 10))); 
    sum /= 10;

    // Getting all digits from the sum
    int digit = 0;
    while (sum >= 1) { // Check if sum >= 1
        digit = (int)(fmod(sum, 10)); 
        sum /= 10;
        // Inserting digits before the ones digit
        insert_at_pos(&ans, 0, digit);
    }

    // Returning Finally
    return ans;
}

void main()
{
    Node *n1 = create_node(7);
    insert_at_pos(&n1, -1, 2);
    insert_at_pos(&n1, -1, 3);
    insert_at_pos(&n1, -1, 3);

    Node *n2 = create_node(5);
    insert_at_pos(&n2, -1, 7);
    insert_at_pos(&n2, -1, 4);

    Node *sum = add_two_numbers(n1, n2);
    display(n1);
    display(n2);
    display(sum);
}