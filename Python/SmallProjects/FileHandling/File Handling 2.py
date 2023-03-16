import os

file = os.path.join("FileHandling", "test.txt")
file2 = os.path.join("FileHandling", "test2.txt")
a = open(file, "r", encoding="utf-8", errors="ignore")
b = open(file2, "a+", encoding="utf-8", errors="ignore")

copy = a.read()
b.write(copy)

a.close()
b.close()

# a+

