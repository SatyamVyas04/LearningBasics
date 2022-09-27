# Program to reverse a given list in its place
list1 = list(eval(input()))
list2 = []
for i in range(0, len(list1)):
    x = list1[i]
    list2.insert(0, x)
print(list1)
print(list2)