
# 1
# 2 4
# 1 2 3
# 2 4 6 8
# 1 2 3 4 10
# 2 4 6 8 10 12
# 1 2 3 4 5 6 14
# 2 4 6 8 10 12 14 16

for _ in range(int(input())):
    n = int(input())
    if n%2==0:
        for i in range(1, n+1):
            print(2*i, end=" ")
        print()
    elif n==1:
        print(1)
    elif n==3:
        print("1 2 3")
    else:
        for i in range(1, n):
            print(i, end=" ")
        print(2*n)