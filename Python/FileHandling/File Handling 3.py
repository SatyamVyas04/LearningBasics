import csv
import os

file = os.path.join("FileHandling", "test.csv")
file2 = os.path.join("FileHandling", "test2.csv")
a = open(file, "r+")
b = open(file2, "r+")

data = csv.reader(a, delimiter=",")
for row in data:
    w = csv.writer(b, delimiter=",")
    w.writerow(row)

a.close()
b.close()

