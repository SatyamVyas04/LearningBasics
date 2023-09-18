/*
 * File: queue.c
 * Author: Siddhartha Chandra
 * Email: siddhartha_chandra@spit.ac.in
 * Created: September 1, 2023
 * Description: This program implements a Queue ADT with a circular array
 */

#include <stdio.h>
#include <stdlib.h>

// Build a Queue Abstract Data structure and perform operations on it
// Operations:
// 1. display
// 2. isFull
// 3. isEmpty
// 4. enqueue
// 5. dequeue
// 6. front
// 7. rear

struct Queue
{
    int front;
    int rear;
    unsigned size;
    char *array;
};

// 0 -> Initialize
struct Queue *initialize_queue(unsigned size)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    queue->array = (char *)malloc(size * sizeof(char));
    return queue;
}

// 1 -> display
void display(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("\n> Queue is Empty\n");
        return;
    }
    
    printf("\n> Queue Front\n");
    
    int i = queue->front;
    do
    {
        printf("> %c\n", queue->array[i]);
        i = (i + 1) % queue->size;
    } while (i != (queue->rear + 1) % queue->size);
    
    printf("> Queue Rear\n\n");
}

// 2 -> isEmpty
int isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

// 3 -> isFull
int isFull(struct Queue *queue)
{
    return (queue->rear + 1) % queue->size == queue->front;
}

// 4 -> enqueue
void enqueue(struct Queue *queue, char item)
{
    if (isFull(queue))
    {
        printf("\n> Dequeue-ing to free space: %c\n", queue->array[queue->front]);
        queue->front = (queue->front + 1) % queue->size;
    }
    
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    
    queue->rear = (queue->rear + 1) % queue->size;
    queue->array[queue->rear] = item;
}

// 5 -> dequeue
char dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("\n> Queue already Empty! \n");
        return '\0';
    }
    
    char front = queue->array[queue->front];
    
    if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->size;
    }
    
    return front;
}

// 6 -> front
char front(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        return '\0';
    }
    return queue->array[queue->front];
}

// 7 -> rear
char rear(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        return '\0';
    }
    return queue->array[queue->rear];
}

// void main()
// {
// 	struct Queue *q = initialize_queue(8);
// 	printf("> IsEmpty: %d\n", isEmpty(q)); // 1 for Empty Queue Array
// 	dequeue(q);							   // Checking for Dequeue in Empty Queue
// 	enqueue(q, 'a');					   // Enqueue-d 8 characters
// 	enqueue(q, 'b');
// 	enqueue(q, 'c');
// 	enqueue(q, 'd');
// 	enqueue(q, 'e');
// 	enqueue(q, 'f');
// 	enqueue(q, 'g');
// 	enqueue(q, 'h');
// 	display(q);						   // Checking Queue
// 	printf("> Front: %c\n", front(q)); // Checking Front and Rear
// 	printf("> Rear: %c\n", rear(q));
// 	printf("> isFull: %d\n", isFull(q));
// 	printf("> Enqueing i to test limitations");
// 	enqueue(q, 'i');							 // Enqueueing when Full
// 	display(q);									 // Checking Queue
// 	printf("> Dequeued Item: %c\n", dequeue(q)); // Checking Dequeue
// 	display(q);									 // Final Display
// }
