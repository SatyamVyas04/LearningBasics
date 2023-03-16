import pickle
import os

file = os.path.join("FileHandling", "test1.dat")

with open(file, 'wb') as f:
    while True:
        op = int(input("Enter 1 to Add Data\
            \nAnd 0 to Exit: "))
        if op == 1:
            name = input('Enter Name: ')
            marks = input("Enter Score: ")
            pickle.dump([name, marks], f)
        elif op == 0:
            break
        
