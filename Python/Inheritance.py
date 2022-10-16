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
        print("EmployeeSalary".center(16, " "), end="|\n")        
        print("-".center(70, "-"))
        print("|"+f"{self.fullname()}".center(20, " "), end="|")
        print(f"{self.email}".center(30, " "), end="|")
        print(f"{self.salary}".center(16, " "), end="|\n") 
        print("-".center(70, "-"))
        print()   

class Developer(Employee):
    raise_amount = 1.10

emp1 = Employee("Satyam", "Vyas", int('100_000'))
emp2 = Developer("Second", "Emp", int('50_000'))

# Displaying complete Details
emp1.Details()
emp2.Details()
print(help(Developer))