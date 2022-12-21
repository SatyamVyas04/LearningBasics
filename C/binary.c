#include <stdio.h>
#include <math.h>
int main() {
    int choice;
    printf("Enter Choice:\n1) Decimal to Binary\n2) Binary to Decimal\n==> ");
    scanf("%d", &choice);
    
    int n;
    switch(choice){
        case 1: //Dec to Bin
        printf("Enter Decimal N: ");
        scanf("%d", &n);
        int power = 0, bin = 0, nr = n;
        while (n>0){
            int r = n%2;
            bin = bin + r * pow(10, power);
            power++;
            n = n/2;
        }
        printf("==> %d in Binary is %d\n", nr, bin);
        break;
        
        case 2: //Bin to Dec
        printf("Enter Binary N: ");
        scanf("%d", &n);
        int p = 0, dec=0, nr2 = n; //p for power
        while (n>0){
            int mult = pow(2, p); //getting index);
            int r = n%10;
            dec += r*mult;
            p++;
            n/=10;
        }
        printf("==> %d in Decimal is %d\n", nr2, dec);
        break;
        
        default: 
        printf("Enter a valid input");
        
    }
    return 0;
}
