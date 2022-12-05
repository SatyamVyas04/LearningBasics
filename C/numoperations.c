# include <stdio.h>
int main(){
float a, b;
printf("Enter a and b (comma seperated): ");
scanf("%f, %f", &a, &b);
printf("Sum = %f\n", a+b);
printf("Difference = %f\n", a-b);
printf("Product = %f\n", a*b);
printf("Quotient = %4.5f\n", a/b);
return 0;

}
