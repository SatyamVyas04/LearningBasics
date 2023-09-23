#include <stdio.h>
#include <math.h>

int main() {
    float p, r, n;
    printf("Enter Pricipal Amount: ");
    scanf("%f", &p);
    printf("Enter Rate of Interest: ");
    scanf("%f", &r);
    printf("Enter Number of Years: ");
    scanf("%f", &n);
    float variable = pow(1+r, n);
    printf("EMI is %f", (p*r*variable)/(variable-1));
}
