#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int divsum(int n){
    int root = pow(n, 0.5), sum=0;
    for(int i=2; i<root; i++){
        if(n%i==0){
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
    printf("Amicable Test:\nEnter 2 numbers <a, b>: ");
    scanf("%d, %d", &a, &b);
    if (amicable(a, b)==true){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
} // ERROR AA RHA HAI KUCH...
