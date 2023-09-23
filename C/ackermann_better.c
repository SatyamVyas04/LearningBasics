#include <stdio.h>

void print(int a, int b){
    printf("\n|(0,0)");
    for(int n = 0; n<=a; n++){
        printf("| n =%2d ", n);
    }
    printf("|");

    for(int m = 0; m<=b; m++){
        printf("\n| m=%d ", m);
        for(int n = 0; n<=a; n++){
            printf("| %5d ", ack(m, n));    
        }
        printf("|");
    }
    printf("\n");
}

int ack(int m, int n){
    if (m==0){
        return n+1;
    }
    if (m!=0 && n==0){
        return ack(m-1, 1);
    }
    if (m!=0 && n!=0){
        return ack(m-1, ack(m, n-1));
    }
}

int main() {
    int a, b;
    printf("Enter a and b\nin <a, b> format: ");
    scanf("%d, %d", &a, &b);
    print(b, a);
    return 0;
}
