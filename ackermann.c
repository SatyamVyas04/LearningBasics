#include <stdio.h>

void print(int a, int b){
    printf("\n|(0,0)");
    for(int m = a; m<=b; m++){
        printf("| m=%d ", m);
    }
    printf("|");

    for(int n = a; n<=b; n++){
        printf("\n| n=%d ", n);
        for(int m = a; m<=b; m++){
            printf("| %3d ", ack(m, n));    
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
    print(a, b);
    return 0;
}
