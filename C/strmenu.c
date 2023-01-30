#include <stdio.h>
int main() {
    char a[100];
    char b[100];
    int menu=0;
    printf("Enter the Sentence: ");
    scanf("%[^\n]", a);
    printf("Menu: \n");
    printf("1) Copy String\n");
    printf("2) Find String Length\n");
    printf("3) Compare 2 Strings\n");
    printf("4) String Reversal\n");
    printf("5) Concat 2 Strings\n");
    printf("6) Lower Case to Upper\n");
    printf("==> Enter your Choice: ");
    scanf("%d", &menu);
    
    switch(menu){
    case 1:
    	int i = 0;
    	while (a[i]!='\0'){
    		b[i]=a[i];
    		i++;
    	}
    	b[i] = '\0';
    	printf("\n==> Copied String: ");
		for(int j=0; j<i; j++){
			printf("%c", b[j]);
		}
		printf("\n");
		break;
    case 2:
    	int len=0;
    	while (a[len]!='\0'){
    		len++;
    	}
    	printf("\n==> Length of the String: %d\n", len);
		break;    
    case 3:
    	char buffer;
    	scanf("%c", &buffer);
    	printf("Enter String B: ");
    	scanf("%[^\n]", b);
    	int flag = 0;
    	i = 0;
    	while(a[i]!='\0' && b[i]!='\0'){
    		if(a[i]!=b[i]){
    			flag = 1;
    			break;
    		}
    		i++;
    	}
    	if(flag==0){
    		printf("\n==> Both Sentences are Same...\n");
    	}else{
    		printf("\n==> Both Sentences are NOT Same...\n");
    	}
		break;    
    case 4: 
		break;    
    case 5:
		break;    
    case 6: 
		break;    
    default:
    	printf("Invalid Input\n");
    	break;
    }	
}
    	
    	
    	
    	
    	
