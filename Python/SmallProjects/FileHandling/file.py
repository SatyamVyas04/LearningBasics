import pickle
import os

file = os.path.join("FileHandling", "test1.dat")

with open(file, "rb") as file:
    while True:
        try:
            row = pickle.load(file)
            print(row)
        except EOFError:
            break
