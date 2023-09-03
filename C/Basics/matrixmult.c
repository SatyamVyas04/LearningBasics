# include <stdio.h>
void multiply(int rowsa, int colsa, int rowsb, int colsb, int a[rowsa][colsa], int b[rowsb][colsb])
{
    if (rowsb != colsa)
    {
        printf("\n==> Multiplication is not possible...\n");
        return;
    }
    int i, j, k;
    int c[rowsa][colsb];
    for (i = 0; i < rowsa; i++)
    {
        for (j = 0; j < colsb; j++)
        {
            *(*(c+i)+j) = 0;
        }
    }
    for (i = 0; i < rowsa; i++)
    {
        for (j = 0; j < colsb; j++)
        {
            for (k = 0; k < colsb; k++)
            {
                *(*(c+i)+j) += *(*(a+i)+k) * *(*(b+k)+j);
            }
        }
    }
    printf("\n==> Multiplication of matrices: \n");
    for (i = 0; i < rowsa; i++)
    {
        for (j = 0; j < colsb; j++)
        {
            printf("%d ", *(*(c+i)+j));
        }
        printf("\n");
    }
}

void input2DArray(int rows, int cols, int arr[rows][cols]){
    printf("Enter the elements of the 2D array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter element arr[%d][%d]: ", i, j);
            scanf("%d", *(arr+i)+j);
        }
    }
    printf("==> The Matrix: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", *(*(arr+i)+j));
        }
        printf("\n");
    }
}

int main(){
	int rowsa, colsa;
    printf("Enter the number of rows of A: ");
    scanf("%d", &rowsa);
    printf("Enter the number of columns of A: ");
    scanf("%d", &colsa);
    int A[rowsa][colsa];
    input2DArray(rowsa, colsa, A);
    
    int rowsb, colsb;
    printf("Enter the number of rows of B: ");
    scanf("%d", &rowsb);
    printf("Enter the number of columns of B: ");
    scanf("%d", &colsb);
    int B[rowsb][colsb];
    
    input2DArray(rowsb, colsb, B);
    
    multiply(rowsa, colsa, rowsb, colsb, A, B);
    
    
    
}
