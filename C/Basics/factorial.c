#include <stdio.h>

int fact(int n){
	if (n==2){
		return 2;
	}else if(n==1 || n==0){
		return 1;
	}else if(n<0){
		return 0;
	}else{
		return n*fact(n-1);
	}
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    int ans = fact(n);
    printf("==> %dth Factorial: %d\n", n, ans);
    return 0;
}
