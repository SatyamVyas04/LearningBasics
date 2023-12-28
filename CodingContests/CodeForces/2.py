from math import sqrt
for _ in range(int(input())):
    n = int(input())
    suml = sum(list(map(int, input().split())))
    if sqrt(suml)%1 == 0:
        print("YES")
    else:
        print("NO")