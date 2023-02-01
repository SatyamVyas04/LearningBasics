#include <stdio.h>
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    printf("Enter Size of the Array: ");
    scanf("%d", &n);
    int arr[n];
    
    // Array Input
    printf("Enter Array Elements: \n");
    for(int i = 0; i<n; i++){
        scanf("%d", arr+i);
    }
    
    //Initial Print
    printf("Array before swap: [");
    for(int i = 0; i<n-1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[n-1]);

    //Find Largest and Smallest
    int* pmax; 
    int* pmin;
    int max;
    int min;
    for(int i = 0; i<n; i++){
        if (*(arr+i)>=max){
            pmax = arr+i;
            max = *(arr+i);
        }
    }
    min = max;
    for(int i = 0; i<n; i++){
        if (*(arr+i)<=min){
            pmin = arr+i;
            min = *(arr+i);
        }
    }
    
    // Swap
    swap(pmin, pmax);
    
    // Print array
    printf("Array after swap: [");
    for(int i = 0; i<n-1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[n-1]);
    return 0;
}










