#include <stdio.h>

int main() {
    int a, b, c, r;
    printf("Enter a, b: ");
    scanf("%d, %d", &a, &b);
    
    int initprod = a*b;
    //sorting a and b
    if(b>a){
        c = a;
        a = b;
        b = c;
    } //sorted
    
    //GCD Euclid Method
    r = a%b;
    while (r!=0){
        a = b;
        b = r;
        r = a%b;
    } //Numbers made smaller
    printf("GCD = %d\n", b);
    
    //LCM 
    printf("LCM = %d\n", initprod/b);
}
