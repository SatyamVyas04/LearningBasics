# Text File Parser & I Reverser
a = open(r"/Users/shivamvyas/PycharmProjects/Practicals/Story.txt", "r")
l = a.read()
for i in l.split():
    if i[0] == "i":
        print(i[::-1], end = " ")
    if i[0] == "I":
        print(i[::-1], end = " ")
    else:
        print(i, end = " ")
