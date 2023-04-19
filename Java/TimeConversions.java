// Time class : Hours, Minutes and Seconds
// Write a program that asks the user to enter seconds as integer.
// The program should compute and display the number of hours,
// number of minutes and number of seconds in that seconds.
// For example if user enters 4205 seconds as a input called totSeconds. 
// The answer should be
// Hours : 1
// Minutes : 10
// Seconds : 5
// These calculations can be done in a method name: conversion1() which 
// will also display the result as Hour,minutes and seconds.
// Similarly- if user input is Hour, Minute and Second then write another method
// conversion2() which will have these three parameters and 
// the conversion2 method will compute and display the totSeconds.

// Pseudocode
// class Time
//     variables
//     - hours
//     - minutes
//     - seconds
//     methods
//     - constructor 1 if totseconds entered
//     - constructor 2 if h/m/s entered
//     - conversion 1: totseconds to hms
//     - conversion 2: hms to totseconds
// class timeconversions:
//     methods
//     - main
//         - input user choice: totsecs or hms
//         - construct a time obj resp.
//         - print req. output

import java.util.*;
public class TimeConversions{
    public static void main(String[] args){
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("--- TimeConverter ---");
            System.out.println("> Enter 1 for Time Input in TotSeconds");
            System.out.println("> Enter 2 for Time Input in HMS format");
            System.out.println("> Enter 0 to Exit");
            System.out.print(">> ");
            int opt = sc.nextInt();
            switch(opt){
                case 1:
                    System.out.print("\nEnter time in total seconds: ");
                    int tot = sc.nextInt();
                    Time time = new Time(tot);
                    time.conversion1();
                    break;
                case 2:
                    System.out.print("\nEnter time in H M S format: ");
                    int h = sc.nextInt();
                    int m = sc.nextInt();
                    int s = sc.nextInt();
                    Time time2 = new Time(h, m, s);
                    time2.conversion2();
                    break;
                case 0:
                    System.out.println("\n--- Thank you ---");
                    break;
                default:
                    System.out.println("\nInput Error!");
                    System.out.println("--- Quiting ---");
                    break;
            }
        }
        System.out.println("\n--- End of program ---");
    }
}


class Time{
    int hours;
    int minutes; 
    int seconds;
    int totseconds;
    
    Time(int h, int m, int s){
        this.hours = h;
        this.minutes = m;
        this.seconds = s;
    }
    
    Time(int tot){
        this.totseconds = tot;
    }
    
    void conversion1(){
        // for totseconds to hms
        this.hours = this.totseconds/3600;
        int remsecs = this.totseconds%3600;
        this.minutes = remsecs/60;
        this.seconds = remsecs%60;
        System.out.println("Hours: "+this.hours);
        System.out.println("Minutes: "+this.minutes);
        System.out.println("Seconds: "+this.seconds);
    }
    
    void conversion2(){
        // for hms to totseconds
        this.totseconds = this.hours*3600 + this.minutes*60 + this.seconds;
        System.out.println("Totseconds: "+this.totseconds);
    }
    
}
