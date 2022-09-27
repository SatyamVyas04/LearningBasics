# Program to increment values of list members by x
List = list(eval(input()))
x = int(input())
for i in range(0, len(List)):
    List[i] += x
print(List)