/*EXP2a Problem
write a program to simulate a simple banking system in which 
the initial balance and rate of interest are read from the keyboard
and these values are initialised using the constructor member function
The program consists of the foll methods
1) to intialize the balance amount and ROI using const. mem. func
2) to make deposit
3) to withdraw an amount from the balance
4) to find compound interest based on the ROI
5) to know the balance amount
6) to display the menu options

Pseudocode: 
BankAcc class:
    variables:
    - accno. int
    - balance double
    - ROI double
    methods:
     - menu: show all the methods
    - constructor method (accno, balance, ROI)
    - deposit: balance += added
    - withdraw: balance -= removed
    - compound interest: n years taken as parameter, then formula
    - balance check: return balance
   
BankingSystem class:
    objs:
    - bankacc object created
    - show all methods in a while loop
        - based on input, use methods.
        - end on (0)
*/
import java.util.*;
public class BankingSystem{
    public static void main(String[] args){
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("--- Welcome to ABC Bank ---");

            System.out.println("Enter your Balance: ");
            double bal = sc.nextDouble();
            System.out.println("Enter ROI: ");
            double roi = sc.nextDouble();
            System.out.println("Your Bank Account No is 111\n");

            BankAcc acc = new BankAcc(111, bal, roi);

            int opt = 0;
            do{
                acc.menu();
                opt = sc.nextInt();

                if(opt==1){
                    System.out.println("\nEnter the money to be deposited: ");
                    double added = sc.nextDouble();
                    acc.depositmoney(added);

                }else if(opt==2){
                    System.out.println("\nEnter the money to be withdrawn: ");
                    double removed = sc.nextDouble();
                    acc.withdrawmoney(removed);

                }else if(opt==3){
                    System.out.println("\nEnter the number of years: ");
                    int years = sc.nextInt();
                    acc.CI(years);

                }else if(opt==4){
                    acc.balcheck();

                }else if(opt==0){
                    break;

                }else{
                    System.out.println("--- INPUT ERROR ---");
                }
            }while(opt!=0);
        }

        System.out.println("--- Thank you ---");
    }
}

class BankAcc{
    int accno;
    double balance, ROI;
    // Constructor method
    BankAcc(int acc, double bal, double r){
        this.accno = acc;
        this.balance = bal;
        this.ROI = r;
    }
    void menu(){
        System.out.println("\n--- ABC BANK ---"); 
        System.out.println("> Enter 1 to Deposit Money"); 
        System.out.println("> Enter 2 to Withdraw Money"); 
        System.out.println("> Enter 3 to know Compound Interest Money");
        System.out.println("> Enter 4 to Check Balance"); 
        System.out.println("> Enter 0 to Exit: ");
    }

    void depositmoney(double added){
        this.balance += added;
        System.out.println(added + " Rupees deposited to your acc."+this.accno);
    }
    
    void withdrawmoney(double remove){
        this.balance -= remove;
        System.out.println(remove + " Rupees withdrawn from your acc."+this.accno);
    }

    void CI(int t){
        System.out.print("Compound interest on your current balance and rate of interest, after "+t+" years is: ");
        double p = this.balance;
        double r = this.ROI;
        double amount = p*(Math.pow(1+r/100, t));
        System.out.println(amount - p);
    }

    void balcheck(){
        System.out.println("Current balance in acc."+this.accno+" is "+this.balance);
    }
}
