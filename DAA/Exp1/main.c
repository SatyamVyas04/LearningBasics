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
	
	FILE *inputFile;
	inputFile = fopen("./numbers.txt", "r");
	
	if(inputFile == NULL){
      printf("Error!");   
      exit(1);             
   	}
   	
	int num;
	int *arr[100];
	for (int bracket = 0; bracket < 1000; bracket++){
		printf("Bracket %d : ", bracket+1);
		for (int index = 0; index < 100; index++){
			if (fscanf(inputFile, "%d", &num) == 1) {
				    printf("%d ",num);
			}
		}
		printf("\n");
	}
	
	time = clock() - time;
	double time_taken = ((double)time)/CLOCKS_PER_SEC;
	return time_taken;
	return 0;
}
