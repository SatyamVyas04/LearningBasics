# Fibonacci number printer in separate lines

n = int(input())
list1 = [0, 1]
for i in range(n):
    list1.append(list1[i] + list1[i+1])
for j in range(len(list1)):
    print(list1[j])
