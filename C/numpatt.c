#include <stdio.h>
void patt(int rows){
    for(int row = 1; row<=rows; row++){
        for(int col = rows - row; col>0; col-- ){
            printf("   ");
        }
        for(int col = 1; col<=2*row - 1; col++){
            printf("%3d", col);
        }
        printf("\n");
    }
}

int main() {
    int rows;
    printf("Enter n(rows): ");
    scanf("%d", &rows);
    patt(rows);
    return 0;
}
