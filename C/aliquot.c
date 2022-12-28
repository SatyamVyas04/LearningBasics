#include <stdio.h>

void print(int n, int sum){
	printf("=> S(%d) = %d\n", n, sum);
}

int aliquot(int n){
	//sum of divisors
	int sum=1, lim = n/2;
	for(int i = 2; i<=lim; i++){
		if(n%i==0){
			sum+=i;
		}
	}
	
	//break case
	if(n==1){
		sum = 0;
		print(n, sum);
		return 0;
	}
	
	//recursive block
	if(sum == n){
		printf("==> %d is a Perfect Number\n", n);
		return 0;
	}else if(sum!=0){
		print(n, sum);
		aliquot(sum);
	
	}
}

int main(){
	int n;
	printf("==> Enter N to print Aliquot Series: ");
	scanf("%d", &n);
	aliquot(n);
}
// ADD SOME CONDITION FOR AMICABLE



