#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// add void printer to remove redundant printer

void add(int rows, int cols, int a[rows][cols], int b[rows][cols])
{
    int i, j;
    int c[rows][cols];
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("Addition of matrices: \n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

void subtract(int rows, int cols, int a[rows][cols], int b[rows][cols])
{
    int i, j;
    int c[rows][cols];
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("Subtraction of matrices: \n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

void multiply(int rows, int cols, int a[rows][cols], int b[rows][cols])
{
    int i, j, k;
    int c[rows][cols];
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            c[i][j] = 0;
        }
    }
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            for (k = 0; k < cols; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("Multiplication of matrices: \n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

double norm(int rows, int cols, int matrix[rows][cols])
{
    double norm = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            norm += matrix[i][j] * matrix[i][j];
        }
    }
    return sqrt(norm);
}

void transpose(int rows, int cols, int matrix[rows][cols], int transposedMatrix[cols][rows])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
}

void input2DArray(int rows, int cols, int arr[rows][cols])
{
    printf("Enter the elements of the 2D array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter element arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

int main()
{
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int A[rows][cols];
    input2DArray(rows, cols, A);
    int B[rows][cols];
    input2DArray(rows, cols, B);
    add(rows, cols, A, B);
    subtract(rows, cols, A, B);
    multiply(rows, cols, A, B);
    int norma = norm(rows, cols, A);
    int normb = norm(rows, cols, B);
    printf("Norm of A = %d", norma);
    printf("\nNorm of B = %d", normb);
    return 0;
}
