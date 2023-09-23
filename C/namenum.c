# include <stdio.h>
int main(){
char name[15];
int age;

printf("Enter your Name: ");
scanf("%s", name);

printf("Enter your Age: ");
scanf("%d", &age);

printf("=> Good Morning %s \n=> Your Age is %d\n", name, age);
}
