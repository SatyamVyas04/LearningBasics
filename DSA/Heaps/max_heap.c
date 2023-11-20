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
MaxHeap *initHeap(int capacity){
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->array = (int*)malloc(sizeof(int)*capacity);
    heap->capacity = capacity;
    heap->size = 0;
}

// Delete and free the max-heap structure
void destroyHeap(MaxHeap* heap){
    free(heap->array);
    free(heap);
}

/// @brief This restores the heap-order property for max-heap array at index 'i'
/// @param heap 
/// @param i - index of the max-heap array, which might potentialy be breaking the heap order
void heapify(MaxHeap* heap, int i){
    // NEEDS TO BE FIXED
    int largest_element_index;
    int left_child_index = 2*i;
    int right_child_index = 2*i+1;
    int curr_element = heap->array[i];
    
    if((left_child_index < heap->size) || (heap->array[left_child_index] > heap->array[i])){
        largest_element_index = left_child_index;
    }else{
        largest_element_index = i;
    }
    
    if((right_child_index < heap->size) || (heap->array[right_child_index] > heap->array[i])){
        largest_element_index = right_child_index;
    }
    
    int largest_element = heap->array[largest_element_index];
    
    if(largest_element_index != i){
        heap->array[largest_element_index] = curr_element;
        heap->array[i] = largest_element;
        heapify(heap, (int)(i/2)-1);
    }
}

/// @brief This inserts a value into a max-heap
/// @param heap 
/// @param value 
void insert(MaxHeap* heap, int value){
    heap->array[heap->size] = value;
    int parent_index = (int)(heap->size)/2;
    heap->size++;
    if(parent_index>0){
        heapify(heap, parent_index);
    }
    
}

// displays the max element in the MaxHeap array
void peek_max(MaxHeap* heap){
    int max_in_heap = heap->array[0];
    printf("\n> Max in Heap: %2d\n", max_in_heap);
}

// extracts the max element from the MaxHeap array
int extractMax(MaxHeap* heap);


/// @brief - Display the given MaxHeap in a visually clear way.
/// @param heap 
/// @param stop_idx - This index in the MaxHeap array corresponds to the last item of the heap
void display_heap(MaxHeap* heap, int stop_idx){
    printf("\n> Heap Array -> ");
    if(stop_idx > heap->size-1){
        stop_idx = heap->size;
    }
    for(int i = 0; i<stop_idx; i++){
        printf("%2d -> ", heap->array[i]);
    }
    printf("END\n");
}



/// @brief Build max-heap using the Floyd's method. This method should call initHeap
/// @param heap 
MaxHeap *constructHeap(int *arr, int arr_length);


// Sorts the given MaxHeap array in ascending order. 
// Post running this function, heap->array should contain the elements in the sorted order
// NOTE: This function should not use any additional data structures
void heapSort_ascending(MaxHeap* heap);

void main(){
    MaxHeap* heap = initHeap(10);
    insert(heap, 10);
    display_heap(heap, 10);
    insert(heap, 8);
    display_heap(heap, 10);
    insert(heap, 7);
    display_heap(heap, 10);
    insert(heap, 9);
    display_heap(heap, 10);
    insert(heap, 11);
    display_heap(heap, 10);
    insert(heap, 5);
    display_heap(heap, 10);
}
