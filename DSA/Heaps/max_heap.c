/*
 * File: max_heap.c
 * Author: Siddhartha Chandra
 * Email: siddhartha_chandra@spit.ac.in
 * Created: November 5, 2023
 * Description: Create a max-heap ADT using array and implement various operations
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define MaxHeap ADT
typedef struct {
    int *array;
    int size;
    int capacity;
} MaxHeap;

/// @brief Creates an empty max-heap of size 'capacity'
/// @param capacity - max size of heap
/// @return Pointer to MaxHeap
MaxHeap *initHeap(int capacity);

// Delete and free the max-heap structure
void destroyHeap(MaxHeap* heap);

/// @brief This restores the heap-order property for max-heap array at index 'i'
/// @param heap 
/// @param i - index of the max-heap array, which might potentialy be breaking the heap order
void heapify(MaxHeap* heap, int i);

/// @brief This inserts a value into a max-heap
/// @param heap 
/// @param value 
void insert(MaxHeap* heap, int value);

// displays the max element in the MaxHeap array
void peek_max(MaxHeap* heap);

// extracts the max element from the MaxHeap array
int extractMax(MaxHeap* heap);


/// @brief - Display the given MaxHeap in a visually clear way.
/// @param heap 
/// @param stop_idx - This index in the MaxHeap array corresponds to the last item of the heap
void display_heap(MaxHeap* heap, int stop_idx);



/// @brief Build max-heap using the Floyd's method. This method should call initHeap
/// @param heap 
MaxHeap *constructHeap(int *arr, int arr_length);


// Sorts the given MaxHeap array in ascending order. 
// Post running this function, heap->array should contain the elements in the sorted order
// NOTE: This function should not use any additional data structures
void heapSort_ascending(MaxHeap* heap);
