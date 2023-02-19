#include <stdio.h>

// Write a program which inputs N followed by the prices of N items. The program should
// output the price at which each item is offered in a sale. The sale price is calculated as follows.
// The original price is reduced by 10%, the resulting quantity raised to the nearest pound and then
// 1 penny subtracted from it. If the resulting quantity is less than the original price then the new
// price is output, otherwise the old price is output together with a warning message.

int main(){
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    float arr[n];
    for(int i = 0; i<n; i++){
        printf("Enter Original Price of %d item: ", i+1);
        scanf("%f", arr[i]);
    }

    float sale[n];
    for(int i = 0; i<n; i++){
        int round = arr[i]*1.1;
        sale[n] = round - 0.01;
    }
    
    printf("ITEM\tOriginal Price\tSale Price");
    for(int i = 0; i<n; i++){
        if(sale[n]<arr[n]){
            printf("%-4d\t%15f\t%10f\n", i, arr[i], sale[i]);
        }else{
            printf("%-4d\t%15f\t%10f - ERROR\n", i, arr[i], sale[i]);
        }
    }

}