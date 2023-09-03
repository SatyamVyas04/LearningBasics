# include <stdio.h>
int gcd(int a, int b){
	if (b>a){
		a = a+b;
		b = a-b;
		a = a-b;
	}
	int r = a%b;
	while (r!=0){
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}

void rprime(int a, int b){
	if (gcd(a, b) == 1){
		printf("==> Yes, %d and %d are relatively prime\n", a, b);
	}else{
		printf("==> No, %d and %d are NOT relatively prime\n", a, b);	
	}
}

int main(){
	int a, b;
	printf("Enter 2 Numbers <a, b>: ");
	scanf("%d, %d", &a, &b);
	rprime(a, b);
}
