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

emp1 = Employee("Satyam", "Vyas", int('100_000'))
emp2 = Employee("Test", "User", int('50_000'))
print("Employees working here are:", Employee.n_employees)

# Displaying complete Details
emp1.Details()
emp2.Details()

# Applying for Raise
emp1.Raise()
emp2.Raise()

# After Applying Raise
emp1.Details()
emp2.Details()