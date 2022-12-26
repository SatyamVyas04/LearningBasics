#include <stdio.h>
#include <math.h>

int isprime(int n){
	int root = pow(n, 0.5);
	if (n==1){
		return 0;
	}
	if(n%2==0 && n!=2){
		return 0;
	}else{
		for(int i=3; i<root; i+=2){
			if (n%i==0){
				return 0;
			}
		}
	}
	return 1;
}



void prime(int a, int b){
	int c = a - (a%10) + 1;
	for(c; c<a; c++){
		printf("      ");
	}
	for(a; a<=b; a++){
		if(isprime(a) == 1){
			printf("%5d*", a);
		}else if(a%10==0){
			printf("%5d \n", a);
		}else{
			printf("%5d ", a);
		}
	}
}

void main(){
	int a, b;
	printf("Enter a range <a, b>: ");
	scanf("%d, %d", &a, &b);
	prime(a, b);
}
