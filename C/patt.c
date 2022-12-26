# include <stdio.h>

void pattern(int half){
	for(int x = -half; x<=half; x++){
		if (x == 0){
			continue;
		}
		printf("\n");
		for(int y = -half; y<=half; y++){
			if (y-x>half || x+y>half || x-y>half || -x-y>half){
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
