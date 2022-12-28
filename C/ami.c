#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int divsum(int n){
    int sum=1, lim = n/2; // sum is taken as 1 to start with
    // to account for the one that we miss in the loop
    for(int i=2; i<=lim; i++){
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
}
