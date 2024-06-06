def fn(arr):
    ans = float("inf")
    for i in range(len(arr) - 1):
        ans = min(ans, max(arr[i], arr[i+1]))
    return ans - 1

for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    print(fn(arr))