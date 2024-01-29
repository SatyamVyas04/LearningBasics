# include <stdio.h>
# include <stdlib.h>
# include <time.h>


// Swap Function
void swap(int* x, int* y) { 
  int tmp = *x;  
  *x = *y; 
  *y = tmp; 
} 


// The Insertion Sort in our case sorts the array and returns the sorted array
double insertion_sort(int *array, int len){
	clock_t time = clock();
	
	// Algo
	
	time = clock() - time;
	double time_taken = ((double)time)/CLOCKS_PER_SEC;
	return time_taken;
}


// The Selection Sort in our case sorts the array and returns the sorted array
double selection_sort(int *array, int len){
	clock_t time = clock();
	
	// Algo
	
	time = clock() - time;
	double time_taken = ((double)time)/CLOCKS_PER_SEC;
	return time_taken;
}


int main(){
	int num;
	int mult;
	int* arr = (int *) malloc(100 * sizeof(int));
	int* arr2 = (int *) malloc(100 * sizeof(int));
	clock_t time;
	double time_taken;
	FILE *inputFile;
	
	inputFile = fopen("./numbers.txt", "r");
	if(inputFile == NULL){
      printf("Error!");   
      exit(1);             
   	}
   	
   	for(int i = 0; i < 100000; i+=100){
   		mult = i/100 + 1;
   		arr = (int *) realloc(arr, mult*100*sizeof(int));
   		arr2 = (int *) realloc(arr, mult*100*sizeof(int));
   		
   		// Array Input
   		for(int j = 0; j<100; j++){
   			if (fscanf(inputFile, "%d", &num)){
   				arr[i+j] = num;
				arr2[i+j] = num;				
   			}
   		}
   		
   		// Algo Run
   		printf("\n> Insertion Sort Size : %d\t", mult*100);
   		time = insertion_sort(arr, mult*100);
   		printf("Time: %ld\t", time);
   		
   	}
   	
	return 0;
}
