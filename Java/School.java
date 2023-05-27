import java.util.*;

abstract class Marks{
    double s1, s2, s3, s4, s5, s6, s7;
    abstract double getPercentage();
}

class A extends Marks{
    A(double a, double b, double c){
        this.s1 = a; 
        this.s2 = b; 
        this.s3 = c; 
    }
    double getPercentage(){
        return (s1+s2+s3)/3;
    }
}

class B extends Marks{
    B(double d, double e, double f, double g){
        this.s4 = d;
        this.s5 = e;
        this.s6 = f;
        this.s7 = g;
    }
    double getPercentage(){
        return (s4+s5+s6+s7)/4;
    }
}

public class School{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Marks of Student A:- ");
        System.out.print("> Subject1: ");
        double s1 = sc.nextDouble();
        System.out.print("> Subject2: ");
        double s2 = sc.nextDouble();
        System.out.print("> Subject3: ");
        double s3 = sc.nextDouble();
        sc.nextLine();
        
        Marks student1 = new A(s1, s2, s3);
        
        System.out.println("\nEnter Marks of Student B:- ");
        System.out.print("> Subject4: ");
        double s4 = sc.nextDouble();
        System.out.print("> Subject5: ");
        double s5 = sc.nextDouble();
        System.out.print("> Subject6: ");
        double s6 = sc.nextDouble();
        System.out.print("> Subject7: ");
        double s7 = sc.nextDouble();
        sc.nextLine();
        
        Marks student2 = new B(s4, s5, s6, s7);
        
        System.out.printf("\nPercentage of Student 1: %.3f\n", student1.getPercentage());
        System.out.printf("\nPercentage of Student 2: %.3f\n", student2.getPercentage());
        
        if(student1.getPercentage() >= student2.getPercentage()){
            System.out.println("\nMarks of Student A:-");
            sort(student1, 4);
            System.out.println("\nMarks of Student B:-");
            sort(student2, 3);
        }else{
            System.out.println("\nMarks of Student B:-");
            sort(student2, 3);
            System.out.println("\nMarks of Student A:-");
            sort(student1, 4);
        }
    }
    static void sort(Marks m, int limit){
        String[] arrnames = {"Subject1", "Subject2", "Subject3", "Subject4", "Subject5", "Subject6", "Subject7"};
        double [] arr = {m.s1, m.s2, m.s3, m.s4, m.s5, m.s6, m.s7};
        int n = 7;
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - i - 1; j++){
                if (arr[j] > arr[j + 1]) {
                    
                    double temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    
                    String temp2 = arrnames[j];
                    arrnames[j] = arrnames[j + 1];
                    arrnames[j + 1] = temp2;
                }
            }
        }
        for(int i = 6; i>=limit; i--){
            System.out.println(arrnames[i] + ": " + arr[i]);
        }
    }
}