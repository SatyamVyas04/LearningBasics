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
        
    def __repr__(self) -> str:
        return "Employee('{}', '{}', {})".format(self.first, self.last, self.salary)
    
    def __str__(self) -> str:
        return "{} - {}".format(self.fullname(), self.email)
        
    def fullname(self):
        return "{} {}".format(self.first, self.last)
    
    def Raise(self):
        self.salary *= self.raise_amount

    @classmethod
    def set_raise_amount(cls, amount_percentage):
        Employee.raise_amount = amount_percentage
        
    @classmethod
    def from_string(cls, empdata):
        first, last, salary = empdata.split("-")
        return cls(first, last, salary)

emp1 = Employee("Satyam", "Vyas", int('100_000'))
emp2 = Employee("Test", "User", int('50_000'))
print(emp1.__repr__())
print(emp1.__str__())