# include <stdio.h>
# include <stdlib.h>
# include <time.h>


// Swap Function
void swap(int *a, int *b){
	int *temp = a;
	a = b;
	b = temp;
}


// The Insertion Sort in our case sorts the array and returns the sorted array
int* insertion_sort(int *array, int len){
	
	// Algo
	
	return array;
}


// The Selection Sort in our case sorts the array and returns the sorted array
int* selection_sort(int *array, int len){
	
	// Algo
	
	return array;
}


int main(){
	clock_t time = clock();
	
	// Algo Calls	
	
	time = clock() - time;
	double time_taken = ((double)time)/CLOCKS_PER_SEC;
	return time_taken;
	return 0;
}
