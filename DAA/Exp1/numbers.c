# include <stdio.h>
# include <stdlib.h>

int main(){
	FILE *fptr;
	int random_number;
	fptr = fopen("./numbers.txt", "w");
	
	if(fptr == NULL){
      printf("Error!");   
      exit(1);             
   	}
   	
   	for(int i = 0; i<100000; i++){
   		random_number = rand()%10000 + 1;
   		fprintf(fptr, "%d\n", random_number);
   	}
   	
   	fclose(fptr);
	return 0;
}
