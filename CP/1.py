def fn(a, b, c, d):
    if a == c and b == d:
        if a == b:
            return "NO"
        else:
            return "YES"
    sets = sorted([(a, c), (b, d)])
    if sets[1][0] <= sets[0][1]:
        if sets[1][1] > sets[0][1]:
            return "YES"
        return "NO"
    return "YES"

for _ in range(int(input())):
    a, b = map(int, input().split())
    c, d = map(int, input().split())
    print(fn(a, b, c, d))
