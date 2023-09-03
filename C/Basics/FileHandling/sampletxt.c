
#include <stdio.h>
#include <ctype.h>
 
int main(){
    const char *file="sample.txt";
    FILE *f,*f2;
    char ch;
     
    f=fopen(file,"r");
    if(f==NULL){
        printf("Error in opening file.\n");
        return -1;
    }
    f2=fopen("temp.txt","w");
    if(f2==NULL){
        printf("Error in creating temp file.\n");
        return -1;
    }   
    while((ch=fgetc(f))!=EOF){
        if(islower(ch)){
            ch=ch-32;
        }
        putc(ch,f2);                   
    }
    fclose(f);
    fclose(f2);
    rename("sample.txt","sampleold.txt");
    rename("temp.txt","sample.txt");
    remove("sampleold.txt");

    f=fopen(file,"r");
    if(f==NULL){
        printf("Error in opening file.\n");
        return -1;
    }
    printf("Content of file\n");
    while((ch=getc(f))!=EOF){
        printf("%c",ch);
    }
    printf("\n");
    fclose(f);
    return 0;
}