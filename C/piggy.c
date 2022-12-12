# include <stdio.h>
int main(){
int fif, twfive, tw, ten, five;
printf("Enter the number of coins in decreasing value;\n(50, 25, 20, 10, 5) format: ");
scanf("%d, %d, %d, %d, %d", &fif, &twfive, &tw, &ten, &five);
int total = fif*50 + twfive*25 + tw*20 + ten*10 + five*5;
printf("=> Total Money in the Piggy bank is: %d rupees and %d paise\n", total/100, total%100);

}
