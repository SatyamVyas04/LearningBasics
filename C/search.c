#include <stdio.h>
int counter = 0;
int *p1 = &counter;

int binary(int array[], int n, int key){
	int low = 0;
	int high = n - 1;
	int mid = (low+high)/2;
	while (low <= high) {
		*p1+=1;
		if(array[mid] < key){
			low = mid + 1;
		}else if (array[mid] == key){
			return mid;
			break;
		}else{
			high = mid - 1;
		}
		//for next iteration
		mid = (low + high)/2;
		//base case to break out
		if(low > high){
			return -1;
		}
	}
}

int linear(int list[], int n, int key){
	for(int i=0; i<n; i++){
		*p1+=1;
		if(list[i]==key){
			return i;
		}
	}
	return -1;
}


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
	printf("==> Array before sort: [");
	for(int i=0; i<n-1; i++){
		printf("%d, ", arr[i]);
	}
	printf("%d]", arr[n-1]);
	printf("\n");
	
	//Calling SelectionSort
	selectionSort(arr, n);
	
	//Printing array after sorting
	printf("==> Array after sort: [");
	for(int i=0; i<n-1; i++){
		printf("%d, ", arr[i]);
	}
	printf("%d]", arr[n-1]);
	printf("\n");	
	
	//Searching...
	int key = 0;
	printf("\n==> Enter the Element to search: ");
	scanf("%d", &key);
	
	//Linear Search
	printf("\n//USING LINEAR SEARCH: \n");
	int index = linear(arr, n, key);
	if (index!=-1){
		printf("==> KEY Found at Index %d after %d comparisons...\n", index, *p1);
	}else{
		printf("==> KEY NOT Found after %d comparisons\n", *p1);
	}
	
	//Binary Sort
	*p1 = 0;
	printf("\n//USING BINARY SEARCH: \n");
	index = binary(arr, n, key);
	if (index!=-1){
		printf("==> KEY Found at Index %d after %d comparisons...\n", index, *p1);
	}else{
		printf("==> KEY NOT Found after %d comparisons\n", *p1);
	}
}






