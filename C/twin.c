#include <stdio.h>

int prime(int n){
	int d = 3;
	for (d; d<=n/2; d++){
		if(n%d==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int a, b;
	printf("Enter the Range to find twin primes: ");
	scanf("%d, %d", &a, &b);
	// making a odd
	if (a%2==0){
		a++;	
	}
	// traversing among the odd numbers
	while (a<b-2){
		if (prime(a) == 1 && prime(a+2) == 1){
			printf("(%d, %d)\n", a, a+2);
		}
		a+=2;
	}
	printf("are the only twin primes present in this range\n");
}

