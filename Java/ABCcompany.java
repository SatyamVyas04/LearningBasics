// Roles:
// Parent: Employee
// SubClasses:
// - Intern:
//     0.75 base salary
// - Clerk:
//     0.5 base salary
// - Manager:
//     2x base salary

// Employee Methods:
// - getSalary() which return base salary
// - getBonus() which return bonus amt for that role
// - Assume bonus for each subclasses
// - Method Overriding to be used

class Employee{
    String Name;
    private double Salary = 10000;
    private double Bonus = 0;
    
    Employee(String name){
        this.Name = name;
    }
    
    //Setters
    void setSalary(double s){
        this.Salary = s;
    }
    
    void setBonus(double b){
        this.Bonus = b;
    }
    
    //Getters
    double getSalary(){
        return this.Salary;
    }
    
    double getBonus(){
        return this.Bonus;
    }
}

class Intern extends Employee{
    this.setBonus(0.1); //10% of salary
    
    Intern(String name){
        super(name);
    }
    
    //Setting Salary based on role
    this.setSalary(super.getSalary()*0.75);
    
    //Methods
    void getSalary(){
        System.out.println("The Salary for Intern " + this.Name + " = " + super.getSalary());
    }
    
    void getBonus(){
        System.out.println("The Bonus for Intern " + this.Name + " = " + super.getBonus());
    }
}

class Clerk extends Employee{
    this.setBonus(0.05); //5% of salary
    
    Clerk(String name){
        super(name);
    }
    
    //Setting Salary based on role
    this.setSalary(super.getSalary()*0.5); 
    
    //Methods
    void getSalary(){
        System.out.println("The Salary for Clerk " + this.Name + " = " + super.getSalary());
    }
    
    void getBonus(){
        System.out.println("The Bonus for Clerk " + this.Name + " = " + super.getBonus());
    }
}

class Manager extends Employee{
    this.setBonus(0.2); //20% of salary
    
    Manager(String name){
        super(name);
    }
    
    //Setting Salary based on role
    this.setSalary(super.getSalary()*2); 
    
    //Methods
    void getSalary(){
        System.out.println("The Salary for Manager " + this.Name + " = " + super.getSalary());
    }
    
    void getBonus(){
        System.out.println("The Bonus for Manager " + this.Name + " = " + super.getBonus());
    }
}

public class ABCcompany{
    public static void main(String args[]){
        System.out.println("No Errors so far!");
    }
}
