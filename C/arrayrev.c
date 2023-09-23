# include <stdio.h>
void arrayrev(int length, int array[]){
	int temp=0;
	for(int i = 0; i<length/2; i++){
		temp = *(array+i);
		*(array+i) = *(array+length-1-i);
		*(array+length-1-i) = temp;
	}
}


int main(){
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
	
	//FUNCTION CALL
	arrayrev(n, arr);
	
	// Print array
    printf("Array after swap: [");
    for(int i = 0; i<n-1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[n-1]);
    return 0;
}
