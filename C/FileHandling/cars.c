// Set up a file containing vehicle Records which hold registration number and owner information 
// (name and address). Write a program which, given a vehicle’s registration number, will rapidly 
// retrieve and print the owner information

#include <stdio.h>
int main(){
    const char *file="carinfo.txt";
    
    f=fopen(file,"w+");
    if(f==NULL){
        printf("Error in opening file.\n");
        return -1;
    }



    return 0;
}
