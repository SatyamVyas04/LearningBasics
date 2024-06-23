def fn(arr):
    total = 0
    avg = sorted(arr)[1]
    for i in arr:
        total += abs(avg - i)
    return total

for _ in range(int(input())):
    arr = list(map(int, input().split()))
    print(fn(arr))
