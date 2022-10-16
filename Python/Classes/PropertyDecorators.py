# Creating Employee Classes
class Employee:

    def __init__(self, fname, lname):
        self.first = fname
        self.last = lname
    
    @property
    def email(self):
        return f"{self.first}.{self.last}@gmail.com"
    
    @property   
    def fullname(self):
        return "{} {}".format(self.first, self.last)
    
    @fullname.setter
    def fullname(self, name):
        first, last = name.split(" ")
        self.first = first
        self.last = last

emp1 = Employee("Satyam", "Vyas")
print(emp1.first)
print(emp1.email)
print(emp1.fullname)
emp1.fullname = "Shivam Vyas"
print(emp1.first)
print(emp1.email)
print(emp1.fullname)