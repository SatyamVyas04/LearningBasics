# Dictionary Operations
d = {"January": 31,
    "February": 28,
    "March": 31,
    "April": 30, 
    "May": 31,
    "June": 30,
    "July": 31,
    "August": 31,
    "September": 30, 
    "October": 31,
    "November": 30, 
    "December": 31}

print()
print(" Task 1 ".center(45, "-"))
user = input("Enter Month: ").title().strip()
print(f"No. of Days in {user} =", d.get(user))

print()
print(" Task 2 ".center(45, "-"))
l = d.keys()
for i in sorted(l):
    print(i)

print()
print(" Task 3 ".center(45, "-"))
for i in d.keys():
    if d.get(i) == 31:
        print(i)

print()
print(" Task 4 ".center(45, "-"))
l = []
for i in d.keys():
    l.append(f"{d.get(i)} - {i}")
l.sort()
for i in l:
    a, b = i.split(" - ")
    print(f"{b} - {a}")