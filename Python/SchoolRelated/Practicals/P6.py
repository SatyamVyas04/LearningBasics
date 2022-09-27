import csv
f = open(r"/Users/shivamvyas/PycharmProjects/Practicals/data.csv",'r')
d=csv.reader(f)
next(f) #To Skip Header Row
k = 0
adm = int(input("Enter admission number: "))
for row in d:
    if int(row[0])==adm:
       print("Adm no  = ", row[0])
       print("Name    = ", row[1])
       print("Class   = ", row[2])
       print("Section = ", row[3])
       print("Marks   = ", row[4])
       quit()
    else:
      pass
print("Record Not Found")