#include <stdio.h>

int gcdr(int a, int b){
	int r = a%b;
	if(r!=0){
		gcdr(b, r);
	}else{
		return b; 
	}
}


int main(){
	int a, b;
	printf("Enter A: ");
	scanf("%d", &a);
	printf("Enter B: ");
	scanf("%d", &b);
	int gcd = gcdr(a, b);
	printf("\n==> GCD of %d and %d is %d\n", a, b , gcd);
}
