# include <stdio.h>
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(int arr[][2], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j][1] > arr[j + 1][1]){
                swap(&arr[j][1], &arr[j + 1][1]);
                swap(&arr[j][0], &arr[j + 1][0]);
			}
}


int main(){
	int n, year;
	printf("Enter the Current Year: ");
	scanf("%d", &year);
	printf("Enter the Number of Employees: ");
	scanf("%d", &n);
	int emp[n][2];
	for(int i = 0; i<n; i++){
		int age=0;
		printf("Enter Details of Emp%d: ", i+1);
		scanf("%d %d", &emp[i][0], &age);
		emp[i][1] = year + 65 - age;
	}
	
	//print matrix
	printf("==> The Employee Table \n(ID, RetirementYear)\n");
	for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%4d ", emp[i][j]);
        }
        printf("\n");
    }
    
    //sort
    bubbleSort(emp, n);
    
    //print
    for(int i = 0; i<n; i++){
        int current_retirement_year = emp[i][1];
        printf("Year of Retirement %d\n", current_retirement_year);
        printf("List of Employees: ");
        for(int j = 0; j<n; j++){
            if (emp[j][1]==current_retirement_year){
                printf("%d ", emp[j][0]);
            }
        }        
        printf("\n");
    }
}
