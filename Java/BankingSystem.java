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
    BankAcc acc = new BankAcc(111, 10000, 10);
    System.out.println("--- Welcome to ABC Bank ---");
    acc.menu();
}

class BankAcc{
    Scanner sc = new Scanner(System.in)
    int accno;
    double balance, ROI;
    // Constructor method
    BankAcc(int acc, double bal, double r){
        this.accno = acc;
        this.balance = bal;
        this.ROI = r;
    }
    int menu(){
        System.out.println("> Enter 1 to Deposit Money"); 
        System.out.println("> Enter 2 to Withdraw Money"); 
        System.out.println("> Enter 3 to know Compound Interest Money");
        System.out.println("> Enter 4 to Check Balance"); 
        System.out.println("> Enter 0 to Exit: ");
        int opt = sc.nextInt();
        if(opt==1){
            System.out.println("\nEnter the money to be deposited: ");
            double added = sc.nextDouble();
            // Method call
            depositedmoney(added);
        }else if(opt==2){
            System.out.println("\nEnter the money to be withdrawn: ");
            double removed = sc.nextDouble();
            // Method call
            withdrawmoney(removed);
        }else if(opt==3){
            System.out.println("\nEnter the number of years: ");
            int years = sc.nextInt();
            // Method call
            CI(years);
        }else if(opt==4){
            // Method call
            balcheck();
        }else if(opt==0){
            System.out.println("--- THANK YOU!!! ---");
            return;
        }else{
            System.out.println("--- INPUT ERROR ---");
            return;
        }
    }
    void depositmoney(double added){
        this.balance += added;
        System.out.println(added + " Rupees deposited to your acc."+this.accno);
        menu();
    }
    void withdrawmoney(double remove){
        this.balance -= remove;
        System.out.println(remove + " Rupees withdrawn from your acc."+this.accno);
        menu();
    }
    void CI(int t){
        System.out.print("Compound interest on your current balance and rate of interest, after "+n+" years is: ");
        double p = this.balance;
        double roi = this.ROI;
        double amount = p*(Math.pow(1+r/100, 10));
        System.out.print(amount - p);
        menu();
    }
    void balcheck(){
        System.out.println("Current balance in acc."+this.accno+" is "+this.balance);
        menu();
    }
}
