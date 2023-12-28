for _ in range(int(input())):
    n = int(input())
    s = input()
    i = 0
    ans = ""
    v = ["a", "e", "i", "o", "u"]
    while i < n-3:
        a, b, c, d = s[i], s[i+1], s[i+2], s[i+3]
        if (a not in v) and (b in v) and (c not in v) and (d not in v):
            ans += a+b+c+"."
            i += 3
        else:
            ans += a+b+"."
            i += 2
    print(ans + s[i:])