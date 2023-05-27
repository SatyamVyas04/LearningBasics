class Employee {
    String Name;
    private float Salary = 10000;
    private float Bonus;

    Employee(String name) {
        this.Name = name;
    }

    // Setters
    void setSalary(float s) {
        this.Salary = s;
    }

    void setBonus(float b) {
        this.Bonus = b;
    }

    // Getters
    float getSalary() {
        return this.Salary;
    }

    float getBonus() {
        return this.Bonus;
    }
}

class Intern extends Employee {
    Intern(String name) {
        super(name);
        super.setBonus(0.1f); // 10% of salary
        super.setSalary(super.getSalary() * 0.75f); // Setting Salary based on role
    }

    // Methods
    @Override
    float getSalary() {
        return super.getSalary();
    }

    @Override
    float getBonus() {
        return super.getBonus();
    }
}

class Clerk extends Employee {
    Clerk(String name) {
        super(name);
        super.setBonus(0.05f); // 5% of salary
        super.setSalary(super.getSalary() * 0.5f); // Setting Salary based on role
    }

    // Methods
    @Override
    float getSalary() {
        return super.getSalary();
    }

    @Override
    float getBonus() {
        return super.getBonus();
    }
}

class Manager extends Employee {
    Manager(String name) {
        super(name);
        super.setBonus(0.2f); // 20% of salary
        super.setSalary(super.getSalary() * 2f); // Setting Salary based on role
    }

    // Methods
    @Override
    float getSalary() {
        return super.getSalary();
    }

    @Override
    float getBonus() {
        return super.getBonus();
    }
}

public class ABCcompany {
    public static void main(String[] args) {
        Employee x = new Intern("X");
        Employee y = new Clerk("Y");
        Employee z = new Manager("Z");
        System.out.println("\n> Salary of Intern " + x.Name + " is " + x.getSalary());
        System.out.println("> Bonus of Intern " + x.Name + " is " + x.getBonus() + "%");
        System.out.println("\n> Salary of Clerk " + y.Name + " is " + y.getSalary());
        System.out.println("> Bonus of Clerk " + y.Name + " is " + y.getBonus() + "%");
        System.out.println("\n> Salary of Manager " + z.Name + " is " + z.getSalary());
        System.out.println("> Bonus of Manager " + z.Name + " is " + z.getBonus() + "%");

        System.out.println("\n> Final Salary after bonus: ");
        x.setSalary(x.getSalary()*(1+x.getBonus()));
        y.setSalary(y.getSalary()*(1+y.getBonus()));
        z.setSalary(z.getSalary()*(1+z.getBonus()));
        System.out.println("> Salary of Intern " + x.Name + " is " + x.getSalary());
        System.out.println("> Salary of Clerk " + y.Name + " is " + y.getSalary());
        System.out.println("> Salary of Manager " + z.Name + " is " + z.getSalary());
    }
}
