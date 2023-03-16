import os

file = os.path.join("FileHandling", "test.txt")
a = open(file, "r", encoding="utf-8", errors="ignore")
names = []
numbers = []

str = a.readline()
while str:
    str2 = str.split(" ")
    name = str2[0]
    number = str2[1]
    names.append(name)
    numbers.append(number[:-1])
    str = a.readline()
print("Name : Numbers")
for i in range(len(names)):
    print(names[i], ":", numbers[i])

