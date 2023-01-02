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

void patt(int rows){
    for(int row = -1; row<rows; row++){
        for(int col = rows - row; col>0; col-- ){
            printf("  ");
        }
        for(int col = 0; col<= row + 1; col++){
            int max = row+1;
            int p = fact(max)/(fact(col)*fact(max-col));
            printf("%4d", p);
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
