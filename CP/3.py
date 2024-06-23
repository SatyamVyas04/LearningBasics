from collections import Counter
def fn(s, ind, c, n, m):
    counts = Counter(ind)
    c.sort()
    hashmap = {}
    for i in sorted(counts.keys()):
        value = counts[i]
        while value > 1:
            c.pop()
            value -= 1
        hashmap[i] = c.pop(0)            
    for i in hashmap:
        s[i-1] = hashmap[i]
    return "".join(s)

for _ in range(int(input())):
    n, m = map(int, input().split())
    s1 = list(input())
    idx = list(map(int, input().split()))
    s2 = list(input())
    print(fn(s1, idx, s2, n, m))