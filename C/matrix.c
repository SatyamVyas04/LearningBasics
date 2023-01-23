#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void add(int a[][10], int b[][10], int m, int n) {
    int i, j;
    int c[10][10];
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("Addition of matrices: \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

void subtract(int a[][10], int b[][10], int m, int n) {
    int i, j;
    int c[10][10];
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("Subtraction of matrices: \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

void multiply(int a[][10], int b[][10], int m, int n, int p, int q) {
    int i, j, k;
    int c[10][10];
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            c[i][j] = 0;
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("Multiplication of matrices: \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

void input2DArray(int rows, int cols, int arr[rows][cols]) {
    printf("Enter the elements of the 2D array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int A[rows][cols];
    input2DArray(rows, cols, A);
    int B[rows][cols];
    input2DArray(rows, cols, B);
    return 0;
}
