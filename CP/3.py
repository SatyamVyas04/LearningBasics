from math import gcd


def fn(arr):
    ans = []
    x = 1
    for i in arr:
        y = gcd(x, i)
        y = i//y
        x = x * y
    
    s = 0
    for i in arr:
        s += x//i
        ans.append(f"{x//i}")
    if s >= x:
        return -1
    else:
        return " ".join(ans)

for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    print(fn(arr))