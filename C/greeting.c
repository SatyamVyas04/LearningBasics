# include <stdio.h>
int main(){

const int str = 20;
char fname[str];
char lname[str];
long long int uid;
printf("Please Enter your Name: ");
scanf("%s %s", fname, lname);
printf("Enter your UID Number: ");
scanf("%lld", &uid);
printf("Good Morning.\n\tWelcome %s %s!!!\n\tYour UID is %lld\n",fname, lname, uid);

}
