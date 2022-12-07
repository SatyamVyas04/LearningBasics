#include <stdio.h>
#include <math.h>
/*Write a C program that calculates total interest on a given amount for a given period. Show the results for a)SI*/
/*b)CI i)Compounded Annually ii)Compounded Semi Annually iii)Compounded Quarterly iv) Compounded Monthly v) Compounded Daily*/
int main(){
double p, r, n;
printf("Enter the Base Amount: ");
scanf("%lf", &p);
printf("Enter the Rate of Interest: ");
scanf("%lf", &r);
printf("Enter the Period/Time/Years: ");
scanf("%lf", &n);

/*Finding all Interests*/
double si, cia, cisa, ciq, cim, cid;
si = p*r*n/100;
cia = p*pow(1+r/100, n) - p;
cisa = p*pow(1+r/200, n*2) - p;
ciq = p*pow(1+r/400, n*4) - p;
cim = p*pow(1+r/1200, n*12) - p;
cid = p*pow(1+r/36500, n*365) - p;
printf("\n==> Simple Interest Accumulated: %lf\n", si);
printf("==> Compounded Interest Accumulated: \n");
printf("\ta) Compounded Annually: %lf\n", cia);
printf("\tb) Compounded SemiAnnually: %lf\n", cisa);
printf("\tc) Compounded Quarterly: %lf\n", ciq);
printf("\td) Compounded Monthly: %lf\n", cim);
printf("\te) Compounded Daily: %lf\n", cid);

}
