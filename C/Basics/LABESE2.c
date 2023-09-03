#include <stdio.h>

// Write a program which inputs N followed by N pairs of numbers. The first of each pair
// represents the price of an item on a menu, the second the quantity eaten by a customer. The
// restaurant imposes a 10% service charge. The output from your program should itemized bill.

typedef struct{
    int price;
    int quantity;
}order;

int main(){
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    
    order arr[n];
    for(int i = 0; i<n; i++){
        printf("Enter Price/Quantity for %d item: ", i+1);
        scanf("%d/%d", &arr[i].price, &arr[i].quantity);
    }

    int billprice=0;
    for(int i = 0; i<n; i++){
        billprice += arr[i].price*arr[i].quantity;
    }
    
    billprice*=1.1;
    printf("Final Bill: %d", billprice);
}