#include <stdio.h>
#include <math.h>
int main() {
    int num, n=0, sum=0;
    printf("Enter a Number: ");
    scanf("%d", &num);
    int num2 = num;
    int finnumcheck = num;
    
    //Finding Count
    while(num2!=0){
        num2 /=10;
        n++;
    }
    
    //Finding Sum
    while (num!=0){
        int x = num%10;
        sum+=pow(x, n);
        num = num/10;
    }
    //Checking for Armstrong Num
    if (finnumcheck != sum){
        printf("%d is not an Armstrong Number\n", finnumcheck);
    }else{
        printf("%d is an Armstrong Number\n", finnumcheck);
    }
}
