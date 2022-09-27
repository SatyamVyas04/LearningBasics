import mysql.connector as c
from mysql.connector import Error

# MySQL Connection
connection = c.connect(host="localhost",
                user="root",
                passwd="Satyam$0105")
if connection.is_connected():
    cursor = connection.cursor()
    dbinfo = connection.get_server_info()
    print("\n>> Successfully connected to MySQL Server Version", dbinfo)
else:
    print("\n>> Connection Failed")
    quit()

print("\n>>Welcome to Record Searcher")
inp = input("Here's the Attributes available to Search a Record\n\
    1.  ID\n\
    2.  Name\n\
    3.  Age\n\
    4.  Sex\n\
    5.  Job\n\
>> Enter your choice here: ")

inp2 = input(">> Enter Search Criteria: ")  

Att_list = ["IndexFixer", "ID", "Name", "Age", "Sex", "Job"]
if 0<int(inp)<=5:
    cursor.execute("USE Term2;")
    cursor.execute(f"Select * from Data where {Att_list[int(inp)]} = '{inp2}'")
    result = cursor.fetchall()
    
else:
    print("Invalid Input...")
    quit()

print(">> Search Results")
print("ID".ljust(10, " "), end="")
print("Name".ljust(20, " "), end="")
print("Age".ljust(10, " "), end="")
print("Sex".ljust(10, " "), end="")
print("Job".ljust(20, " "))
print("".center(90, "-"))

for i in result:
    for j in i:
        if i.index(j) == 0:
            j = str(j)
            print(j.ljust(10, " "), end="")
            continue
        if i.index(j) == 1:
            j = str(j)
            print(j.ljust(20, " "), end="")
            continue
        if i.index(j) == 2:
            j = str(j)
            print(j.ljust(10, " "), end="")
            continue
        if i.index(j) == 3:
            j = str(j)
            print(j.ljust(10, " "), end="")
            continue
        if i.index(j) == 4:
            j = str(j)
            print(j.ljust(20, " "), end="")
            continue    
    print()
print()
