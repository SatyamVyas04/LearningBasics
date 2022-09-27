# Program to create a new table in a pre-existing MySQL database.
import mysql.connector as c
from mysql.connector import Error
import csv

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

# List to save data
l = []

# CSV file opening
file = open(r"/Users/shivamvyas/PycharmProjects/Term 2 File/CSV.csv", "r")
readobject = csv.reader(file)
for data in readobject:
    l.append(data)

# Making Table in MySQL database
cursor.execute("use Term2;")
cursor.execute(f"create table CSV({l[0][0]} int, {l[0][1]} char(255), {l[0][2]} char(255));")

# Data insertion
for i in range(1, len(l)):
    cursor.execute(f"Insert into CSV({l[0][0]}, {l[0][1]}, {l[0][2]}) Values ({eval(l[i][0])}, {l[i][1]}, {l[i][2]});")
connection.commit()
# Check
cursor.execute("select * from CSV;")
print("\n>>\n", cursor.fetchall())