#include <stdio.h>
int rows, cols;

void matrix_print(int arr[rows][cols]){
	for(int i = 0; i<cols; i++){
	printf("\n");
		for(int j = 0; j<rows; j++){
			printf("|%2d |", arr[j][i]);
		}
	}
}

int main() {
    printf("Enter Rows of the Matrix: ");
    scanf("%d", &rows);
    printf("Enter Cols of the Matrix: ");
    scanf("%d", &cols);
    
    int A[rows][cols];
    int B[rows][cols];
    
    for(int i = 0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("Enter [%d][%d]th Element of A: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }
    for(int i = 0; i<rows; i++){
	printf("\n");
		for(int j = 0; j<cols; j++){
			printf("|%2d |", A[i][j]);
		}
	}
	printf("\n\n");
    for(int i = 0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("Enter [%d][%d]th Element of B: ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }
    for(int i = 0; i<rows; i++){
	printf("\n");
		for(int j = 0; j<cols; j++){
			printf("|%2d |", B[i][j]);
		}
	}
	printf("\n\n");
    return 0;
}

