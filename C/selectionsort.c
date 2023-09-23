#include <stdio.h>
void selectionSort(int list[], int last){
	int current=0, walker=0, smallest=0, tempData=0;
	for (current = 0; current < last; current ++){
		smallest = current;
	for (walker=current+1; walker < last; walker++){
		if(list[walker] < list[smallest]){
			smallest = walker;
			// Smallest selected; swap with current element
			tempData = list[current];
			list[current] = list[smallest];
			list[smallest] = tempData;
			}	
		}
	}
}

int main(){
	int n=0;
	printf("Enter the Length of the Array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the Elements of this Array: \n");
	// List input
	for(int i=0; i<n; i++){
		int temp=0;
		printf(": ");
		scanf("%d", &temp);
		arr[i] = temp;
	}
	//Printing array before sorting
	printf("Array before sort: [");
	for(int i=0; i<n-1; i++){
		printf("%d, ", arr[i]);
	}
	printf("%d]", arr[n-1]);
	printf("\n");
	
	//Calling SelectionSort
	selectionSort(arr, n);
	
	//Printing array after sorting
	printf("Array after sort: [");
	for(int i=0; i<n-1; i++){
		printf("%d, ", arr[i]);
	}
	printf("%d]", arr[n-1]);
	printf("\n");	
}





