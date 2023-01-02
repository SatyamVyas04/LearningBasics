#include <stdio.h>

int fibo(int n){
	if (n==0){
		return 0;
	}else if (n==1){
		return 1;
	}else{
		return fibo(n-2) + fibo(n-1);
	}
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    int ans = fibo(n-1);
    printf("==> %dth Fibonacci Number: %d\n", n, ans);
    return 0;
}
