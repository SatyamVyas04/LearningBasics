# include <stdio.h>
int main(){
double fahren;
printf("Enter Temp in Fahrenheit: ");
scanf("%lf", &fahren);

double cels = (fahren-32)*5/9;
printf("\nTemp %.2f in Fahrenheit = %.2f Centigrade\n", fahren, cels);
}
