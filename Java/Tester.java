import java.util.Scanner;
//  Inputs Details of 5 Employees and prints details of Emp with Max Salary
public class Tester{
    public static void main(String[] args){
        String name, id;
        int age;
        double salary;
        char yn;
        boolean status;
        Scanner sc = new Scanner(System.in);
        
        SalariedEmployee[] emps = new SalariedEmployee[5];
        
        for(int i = 0; i<5; i++){
            System.out.print("Enter Name of Employee " + (i+1) + ": ");
            name = sc.nextLine();
            System.out.print("Enter Id of Employee " + (i+1) + ": ");
            id = sc.nextLine();
            System.out.print("Enter Age of Employee " + (i+1) + ": ");
            age = sc.nextInt();
            System.out.print("Enter Salary of Employee " + (i+1) + ": ");
            salary = sc.nextDouble();
            emps[i] = new SalariedEmployee(name, id, age, salary);
            
            System.out.print("Is the Employee Permanent? (Y/N): ");
            yn = sc.next().charAt(0);
            if(Character.toLowerCase(yn) == 'y'){
                emps[i].setstatus(true);
                emps[i].empAllowance();
            }else{
                emps[i].setstatus(false);
                emps[i].empAllowance();
            }
            
            sc.nextLine(); // Buffer Clear
            System.out.print("\n");
        }
        
        int maxint = 0;
        int currentindex = 0;
        double maxsalary = 0;
        
        for(SalariedEmployee s: emps){
            if(s.getempSalary() > maxsalary){
                maxint = currentindex;
                maxsalary = s.getempSalary();
            }
            currentindex++;
        }
        
        int i = 1;
        System.out.println("---------- Details of All Employees ------------");
        System.out.printf("|%-4s|%-10s|%-5s|%-4s|%-10s|%-8s|\n", "Sr", "Name", "ID", "Age", "Salary", "Status");
        System.out.println("+----------------------------------------------+");

        for(SalariedEmployee s: emps){
            System.out.printf("|%-4d|%-10s|%-5s|%-4d|%-10.2f|%-8b|\n", i, s.getName(), s.getId(), s.getAge(), s.getempSalary(), s.getempStatus());
            i++;
        }
        System.out.println("+----------------------------------------------+");
        
        SalariedEmployee s = emps[maxint]; // s has Max Salary
        System.out.println("\nDetails for Employee with Maximum Salary");
        System.out.println("Name: "+ s.getName());
        System.out.println("Id: "+ s.getId());
        System.out.println("Age: "+ s.getAge());
        System.out.println("Salary: "+ s.getempSalary());
        if(s.getempStatus()){
            System.out.println("Status: Permanent\n");
        }else{
            System.out.println("Status: Temporary\n");
        }
    }
}

class Employee{
    private String Name;
    private String Id;
    private int Age;

    Employee(String n, String id, int a){
        setName(n);
        setId(id);
        setAge(a);
    }
    
    // Setters
    void setName(String newname){
        this.Name = newname;
    }
    
    void setId(String newid){
        this.Id = newid;
    }
    
    void setAge(int newage){
        this.Age = newage;
    }
    
    // Getters
    String getName(){
        return this.Name;
    }
    
    String getId(){
        return this.Id;
    }
    
    int getAge(){
        return this.Age;
    }
}

class SalariedEmployee extends Employee{
    private double empSalary;
    private boolean permanentStatus;
    
    SalariedEmployee(String name, String id, int age, double empSalary){
        super(name, id, age);
        setempSalary(empSalary);
    }
    
    // Setters
    void setempSalary(double salary){
        this.empSalary = salary;
    }
    
    void setstatus(boolean status){
        this.permanentStatus = status;
    }
    
    // Getters
    double getempSalary(){
        return this.empSalary;
    }
    
    boolean getempStatus(){
        return this.permanentStatus;
    }
    
    void empAllowance(){
        if(permanentStatus){
            this.empSalary+=2000;
        }
    }
}
