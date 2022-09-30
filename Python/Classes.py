# Creating Employee Classes
class Employee:
    def __init__(self, fname, lname, salary):
        self.first = fname
        self.last = lname
        self.salary = salary
        self.email = fname + "." + lname + "@Python.com"

    
    def fullname(self):
        return "{} {}".format(self.first, self.last)


emp1 = Employee("Satyam", "Vyas", int('100_000'))
emp2 = Employee("Test", "User", int('50_000'))

print(emp1.email)
print(emp2.email)
print(emp1.fullname())