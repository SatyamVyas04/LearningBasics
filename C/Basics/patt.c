# include <stdio.h>

void pattern(int n){
	n/=2;
	for(int x = -n; x<=n; x++){
		if (x == 0){
			continue;
		}
		printf("\n");
		for(int y = -n; y<=n; y++){
			if (y-x>n || x+y>n || x-y>n || -x-y>n){
				printf(" * ");
			}else if(y == 0){
				printf("");
			}
			
			else{
				printf("   ");
			}
		}
	}
}

int main(){
	int n;
	printf("Enter N: ");
	scanf("%d", &n);
	pattern(n);
	printf("\n");
}
