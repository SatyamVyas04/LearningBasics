#include <stdio.h>
#include <string.h>
int main() {
    char sent[100];
    printf("Enter the Sentence: ");
    scanf("%[^\nc]", sent);
    int len = strlen(sent);
    int vowels=0, consonants=0, special=0, spaces=0, charcount=0;
    for(int i=0; i<len; i++){
        charcount++;
        if(sent[i]=='a' || sent[i]=='A' || sent[i]=='e' || sent[i]=='E' || sent[i]=='i' || sent[i]=='I' || sent[i]=='o' || sent[i]=='O' || sent[i]=='u' || sent[i]=='U'){
            vowels++;
        }else if((sent[i]>='a' && sent[i]<='z')||(sent[i]>='A' && sent[i]<='Z')){
            consonants++;
        }else if(sent[i]==' ' || sent[i]=='\t'){
            spaces++;
        }else{
            special++;
        }
    }
    printf("Vowels: %d\nConsonants: %d\nSpecials: %d\n", vowels, consonants, special);
    printf("Spaces: %d\nTotal Characters: %d\n", spaces, charcount-spaces);
    
    // Word Count
    int wordcount=1;
    for(int i = 0; i<len-1; i++){
        if(sent[i]==' ' && sent[i+1]!=' '){
            wordcount++;
        }
        else if(sent[i]=='\t' && sent[i+1]!=' '){
            wordcount++;
        }
        else if(sent[i]==' ' && sent[i+1]!='\t'){
            wordcount++;
        }
        else if(sent[i]=='\t' && sent[i+1]!='\t'){
            wordcount++;
        }
    }
    printf("Words: %d\n", wordcount);
    return 0;
}
