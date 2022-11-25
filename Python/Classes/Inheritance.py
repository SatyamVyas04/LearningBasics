# Creating Employee Classes
class Employee:
    raise_amount = 1.04
    n_employees = 0

    def __init__(self, fname, lname, salary):
        self.first = fname
        self.last = lname
        self.salary = salary
        self.email = fname + "." + lname + "@Python.com"
        Employee.n_employees += 1
        
    def fullname(self):
        return "{} {}".format(self.first, self.last)
    
    def Raise(self):
        self.salary *= self.raise_amount

    def Details(self):
        print(f" Details of {self.fullname()} are as follows ".center(70, "-"))
        print("|"+"EmployeeName".center(20, " "), end="|")
        print("EmployeeEmail".center(30, " "), end="|")
        print("Salary".center(16, " "), end="|\n")        
        print("-".center(70, "-"))
        print("|"+f"{self.fullname()}".center(20, " "), end="|")
        print(f"{self.email}".center(30, " "), end="|")
        print(f"{self.salary}".center(16, " "), end="|\n") 
        print("-".center(70, "-"))
        print()   

class Developer(Employee):
    raise_amount = 1.10
    def __init__(self, fname, lname, salary, prog_lang):
        super().__init__(fname, lname, salary)
        self.prog_lang = prog_lang
    
    def Details(self):
        print(f" Details of {self.fullname()} are as follows ".center(80, "-"))
        print("|"+"DeveloperName".center(20, " "), end="|")
        print("DeveloperEmail".center(30, " "), end="|")
        print("Salary".center(16, " "), end="|")    
        print("Language".center(10, " "), end="|\n")    
        print("-".center(80, "-"))
        print("|"+f"{self.fullname()}".center(20, " "), end="|")
        print(f"{self.email}".center(30, " "), end="|")
        print(f"{self.salary}".center(16, " "), end="|") 
        print(f"{self.prog_lang}".center(10, " "), end="|\n") 
        print("-".center(80, "-"))
        print()

class Manager(Employee):
    raise_amount = 1.08
    def __init__(self, fname, lname, salary, employees=None):
        super().__init__(fname, lname, salary)
        if employees is None:
            self.employees = []
        else:
            self.employees = employees
            
    def add_emp(self, emp):
        if emp not in self.employees:
            self.employees.append(emp)
    
    def remove_emp(self, emp):
        if emp in self.employees:
            self.employees.remove(emp)
    
    def employees_names(self):
        print("-> Employees: ")
        for emp in self.employees:
            print("--->", emp.fullname())
    
emp1 = Developer("Satyam", "Vyas", int('100_000'), "Python")
emp2 = Employee("Second", "Emp", int('50_000'))
mngr1 = Manager("Manager", "Susan", int('90_000'), [emp1])

# Displaying complete Details
emp1.Details()
emp2.Details()
mngr1.Details()