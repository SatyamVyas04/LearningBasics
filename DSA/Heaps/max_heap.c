#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define MaxHeap ADT
typedef struct {
    int *array;
    int size;
    int capacity;
} MaxHeap;

MaxHeap *initHeap(int capacity) {
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->array = (int *)malloc(sizeof(int) * capacity);
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

void destroyHeap(MaxHeap *heap) {
    free(heap->array);
    free(heap);
}

void heapify(MaxHeap *heap, int i) {
    int largest_element_index = i;
    int left_child_index = 2 * i + 1;
    int right_child_index = 2 * i + 2;

    if ((left_child_index < heap->size) && (heap->array[left_child_index] > heap->array[largest_element_index])) {
        largest_element_index = left_child_index;
    }
    if ((right_child_index < heap->size) && (heap->array[right_child_index] > heap->array[largest_element_index])) {
        largest_element_index = right_child_index;
    }
    if (largest_element_index != i) {
        int temp = heap->array[i];
        heap->array[i] = heap->array[largest_element_index];
        heap->array[largest_element_index] = temp;
        heapify(heap, largest_element_index);
    }
}

void insert(MaxHeap *heap, int value) {
    if (heap->size == heap->capacity) {
        return;
    }

    heap->array[heap->size] = value;
    heap->size++;
    int i = heap->size - 1;
    while (i > 0) {
        int parent_index = (i - 1) / 2;
        if (heap->array[i] > heap->array[parent_index]) {
            int temp = heap->array[i];
            heap->array[i] = heap->array[parent_index];
            heap->array[parent_index] = temp;
            i = parent_index;
        } else {
            break;
        }
    }
}

void peek_max(MaxHeap *heap) {
    if (heap->size > 0) {
        int max_in_heap = heap->array[0];
        printf("\n> Max in Heap: %2d\n", max_in_heap);
    } else {
        printf("\n> Heap is empty\n");
    }
}

int extractMax(MaxHeap *heap) {
    if (heap->size == 0) {
        return -1;
    }

    int max_element = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return max_element;
}

void display_heap(MaxHeap *heap, int stop_idx) {
    printf("\n> Heap Array -> ");
    if (stop_idx > heap->size - 1) {
        stop_idx = heap->size;
    }
    for (int i = 0; i < stop_idx; i++) {
        printf("%2d -> ", heap->array[i]);
    }
    printf("END\n");
}

MaxHeap *constructHeap(int *arr, int arr_length) {
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->array = (int *)malloc(sizeof(int) * arr_length);
    heap->capacity = arr_length + 5; // Buffer
    heap->size = arr_length;

    for (int i = 0; i < arr_length; i++) {
        heap->array[i] = arr[i];
    }
    for (int i = (arr_length - 1) / 2; i >= 0; i--) {
        heapify(heap, i);
    }
    return heap;
}

void heapSort_ascending(MaxHeap *heap) {
    int size = heap->size;
    for (int i = heap->size - 1; i > 0; i--) {
        int temp = heap->array[0];
        heap->array[0] = heap->array[i];
        heap->array[i] = temp;
        heap->size--;
        heapify(heap, 0);
    }
    heap->size = size;
}

// int main() {
//     MaxHeap *heap = initHeap(10);
//     insert(heap, 11);
//     display_heap(heap, 10);
//     insert(heap, 8);
//     display_heap(heap, 10);
//     insert(heap, 7);
//     display_heap(heap, 10);
//     insert(heap, 10);
//     display_heap(heap, 10);
//     insert(heap, 12);
//     display_heap(heap, 10);
//     insert(heap, 9);
//     display_heap(heap, 10);

//     peek_max(heap);

//     int extracted_max = extractMax(heap);
//     printf("> Extracted Max: %2d\n", extracted_max);

//     display_heap(heap, 10);

//     int arr[] = {9, 4, 7, 1, 8, 12, 10};
//     int arr_length = sizeof(arr) / sizeof(arr[0]);
//     MaxHeap *constructedHeap = constructHeap(arr, arr_length);

//     printf("\n> Constructed Heap from array: ");
//     display_heap(constructedHeap, constructedHeap->capacity);

//     printf("\n> Sorting the constructed heap in ascending order: ");
//     heapSort_ascending(constructedHeap);
//     display_heap(constructedHeap, constructedHeap->capacity);

//     destroyHeap(heap);
//     destroyHeap(constructedHeap);

//     return 0;
// }

int main() {
    MaxHeap *heap = initHeap(8);
    insert(heap, 25);
    display_heap(heap, 8);
    insert(heap, 18);
    display_heap(heap, 8);
    insert(heap, 30);
    display_heap(heap, 8);
    insert(heap, 15);
    display_heap(heap, 8);
    insert(heap, 21);
    display_heap(heap, 8);

    peek_max(heap);

    int extracted_max = extractMax(heap);
    printf("> Extracted Max: %2d\n", extracted_max);

    display_heap(heap, 8);

    int arr[] = {35, 14, 27, 12, 17, 22};
    int arr_length = sizeof(arr) / sizeof(arr[0]);
    MaxHeap *constructedHeap = constructHeap(arr, arr_length);

    printf("\n> Constructed Heap from array: ");
    display_heap(constructedHeap, constructedHeap->capacity);

    printf("\n> Sorting the constructed heap in ascending order: ");
    heapSort_ascending(constructedHeap);
    display_heap(constructedHeap, constructedHeap->capacity);

    destroyHeap(heap);
    destroyHeap(constructedHeap);

    return 0;
}
