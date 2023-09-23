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
long int ncr(int n, int r){
    int iter = r;
    if (r==0 || r==n){
        return 1;
    }else if (r==1 || r==n-1){
        return n;
    }else{
        int numerator = 1;
        for(iter; iter>0; iter--){
            numerator *= n;
            n--;
        }
        int ans = numerator/fact(r);
        return ans;
    }
}

void patt(int rows){
    for(int row = -1; row<rows; row++){
        for(int col = rows - row; col>0; col-- ){
            printf("   ");
        }
        for(int col = 0; col<= row + 1; col++){
            int max = row+1;
            long int p = ncr(max, col);
            printf("%6ld", p);
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
