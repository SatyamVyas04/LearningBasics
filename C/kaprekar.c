#include <stdio.h>
#include <math.h>

int digitcount(int num){ //counts digits
	int digits = 0;
	while (num>0){
		num/=10;
		digits ++;
	}
	return digits;
}

int main(){
	int n;
	printf("Enter a Number: ");
	scanf("%d", &n);
	int ns = n*n; //square found
	int digits = digitcount(n); //digits in original counted

	//kaprekar check
	double right=0; 
	int left=0;
	int div = pow(10, digits);
	right = ns % div;
	left = ns / div;
	int sum = left+right;
	if (sum==n){
		printf("YES, %d is a Kaprekar number\n", n);
	}else{
		printf("YES, %d is not a Kaprekar number\n", n);
	}
}
