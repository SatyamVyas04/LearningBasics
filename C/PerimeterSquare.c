#include <stdio.h>
// Perimeter of Rectangle
int main() {
    float l, b;
    printf("Enter the Length of the Rectangle: ");
    scanf("%f", &l);
    printf("Enter the Breadth of the Rectangle: ");
    scanf("%f", &b);
    printf("The Perimeter of the Rectangle is %f", 2*(l+b));
}