#include <stdio.h>
#include <math.h>

void print(int i){
	printf("==> %d\n", i);
}

int perf(int n){
	int sum = 0, half = n/2;
	printf("Divisors of %d are:\n", n);
	for(int i=1; i<=half; i++){
		if (n%i==0){
			print(i);
			sum+=i;
		}
	}
	return sum;
}

int main(){
	// CODE
	int n;
	printf("Enter N: ");
	scanf("%d", &n);
	int perfs = perf(n);
	if (perfs == n){
		printf("\n==> %d is a Perfect Number\n", n);
	}else{
		printf("\n==> %d is not a Perfect Number\n", n);
	}
}
