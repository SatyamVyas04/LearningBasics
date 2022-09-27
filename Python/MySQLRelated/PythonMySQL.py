import random
import mysql.connector as c

# MySQL connection
connection = c.connect(host="localhost", user="root", passwd="Satyam$0105")
if connection.is_connected() == True:
    cursor = connection.cursor()
    dbinfo = connection.get_server_info()
    print("\n>> Successfully connected to MySQL Server Version", dbinfo)
else:
    print(">> Connection Failed!")
    quit()

# Setup
cursor.execute("Use Python")
n = int(input("Kitne Records Daalne Hain? Batao: "))
name = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "R"]
sex = ["M", "F"]
job = ["Baker", "Teacher", "Painter", "Engnr", "CA", "Businessman", "Athelete"]
for i in range(n):
    cursor.execute(f"insert into Employees(ID, Name, Age, Sex, Job) Values({i+1}, '{name[i]}', {random.randrange(18, 30)}, '{random.choice(sex)}', '{random.choice(job)}');")
    connection.commit()