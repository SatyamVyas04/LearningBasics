import collections
import statistics
import math

for _ in range(int(input())):
    n, v = map(int, input().split())
    v2 = v
    d = collections.defaultdict(int)
    for i in range(n):
        x, y = map(int, input().split())
        d[x] = y
    count = n
    while n:
        curr = max(d, key=d.get)
        if curr>v:
            d.pop(curr)
            n-=1
        else:
            v -= d[curr]
            if v>0:
                d.pop(curr)
                n-=1
            else:
                break
    print(v2-v)
    # KNAPSACK_