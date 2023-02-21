// Set up a file containing vehicle Records which hold registration number and owner information 
// (name and address). Write a program which, given a vehicle’s registration number, will rapidly 
// retrieve and print the owner information

#include <stdio.h>
#include <string.h>

typedef struct{
    int regisnum;
    char name[30];
    char address[100];
}car;

int main(){
    const char *file="carinfo.txt";
    FILE* f=fopen(file,"w");
    if(f==NULL){
        printf("Error in opening file.\n");
        return -1;
    }
    
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    car cars[n];
    for(int i = 0; i<n; i++){
        printf("Enter Registration Number of Car %d: ", i+1);
        scanf("%d", &cars[i].regisnum);
        printf("Enter Name: ");
        scanf("%s", &cars[i].name);
        printf("Enter Address: ");
        scanf("%s", &cars[i].address);
    }

    for(int i = 0; i<n; i++){
        fprintf(f, "%d", cars[i].regisnum);
        fputs("\t", f);
        fputs(cars[i].name, f);
        fputs("\t", f);
        fputs(cars[i].address, f);
        fputs("\n", f);
    }
    fclose(f);

    //Reopen File
    f = fopen(file, "r");
    if (f == NULL) {
        printf("Error in opening file.\n");
        return -1;
    }

    n = 0;
    while (fscanf(f, "%d %[^\t\n] %[^\t\n]", &cars[n].regisnum, cars[n].name, cars[n].address) != EOF) {
        n++;
    }
    fclose(f);

    int search_reg_num;
    printf("Enter Registration Number to search: ");
    scanf("%d", &search_reg_num);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (cars[i].regisnum == search_reg_num) {
            printf("Name: %s\n", cars[i].name);
            printf("Address: %s\n", cars[i].address);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Registration Number not found.\n");
    }

    return 0;
}
