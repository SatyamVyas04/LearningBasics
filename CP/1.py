# A

def fn(n):
    return " ".join(map(str, list(range(1, n+1))))

for _ in range(int(input())):
    n = int(input())
    print(fn(n))

