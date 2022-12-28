#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int divsum(int n){
    int sum = 0, half = n/2;
	for(int i=1; i<=half; i++){
		if (n%i==0){
			sum+=i;
		}
	}
	return sum;
}

bool amicable(int a, int b){
    if (divsum(a) == b && divsum(b) == a){
        return true;
    }else{
        return false;
    }
}

int main() {
    int a, b;
    printf("==> Amicable Test:\nEnter 2 numbers <a, b>: ");
    scanf("%d, %d", &a, &b);
    if (amicable(a, b)==true){
        printf("\nYES, the given numbers %d and %d are AMICABLE\n", a, b);
    }else{
        printf("\nNO, the given numbers %d and %d are not AMICABLE\n", a, b);
    }
    return 0;
}

