from time import sleep

string = "Redirecting in..."
string2 = "Redirecting..."
for letter in string: 
    print(letter, end= "")
    sleep(0.05)

for i in range(5, 0, -1):
    print(i, end=" ")
    sleep(1)
print()

print(string2)