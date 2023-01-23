#include <stdio.h>
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

void rotate_once_right(int arr[], int n){
    int temp = arr[n-1];
    for(int i = n-2; i>=0; i--){
        arr[i+1] = arr[i];
    }
    arr[0] = temp;
}
void rotate_once_left(int arr[], int n){
    int temp = arr[0];
    for(int i = 1; i<=n-1; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}
int main() {
    int n=0;
	printf("==> Enter the Length of the Array: ");
	scanf("%d", &n);
	int arr[n];
	printf("==> Enter the Elements of this Array: \n");
	// List input
	for(int i=0; i<n; i++){
		int temp=0;
		printf(": ");
		scanf("%d", &temp);
		arr[i] = temp;
	}
	//print
	printf("Array: [");
	for(int i=0; i<n-1; i++){
		printf("%d, ", arr[i]);
	}
	printf("%d]", arr[n-1]);
	printf("\n");
	//rotations
	int right;
	printf("==> Enter Right Rotations: ");
	scanf("%d", &right);
	int right2 = right%n;
	for(int turns = 0; turns<right2; turns++){
    	rotate_once_right(arr, n);
	}
	//print
	printf("Array after %d Right Rotations: [", right);
	for(int i=0; i<n-1; i++){
		printf("%d, ", arr[i]);
	}
	printf("%d]", arr[n-1]);
	printf("\n");
	//rotations
	int left;
	printf("==> Enter Left Rotations: ");
	scanf("%d", &left);
	int left2 = left%n;
	for(int turns2 = 0; turns2<left2; turns2++){
    	rotate_once_left(arr, n);
	}
	//print
	printf("Array after %d Left Rotations: [", left);
	for(int i=0; i<n-1; i++){
		printf("%d, ", arr[i]);
	}
	printf("%d]", arr[n-1]);
	printf("\n");
    return 0;
    return 0;
}
