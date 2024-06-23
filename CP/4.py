def fn(n, s):
    if "0" in s:
        return 0
    
    minpair = float("inf")
    ps, pe = 0, 0
    
    for r in range(2, n+1):
        l = r - 2
        pair = int(s[l:r])
        if pair < minpair:
            minpair = pair
            ps, pe = l, r

    ans = []
    for i in range(ps):
        ans.append(s[i])
        if s[i] == "1":
            ans.append("*")
        else:
            ans.append("+")
    
    ans.append(s[ps:pe])
    
    for i in range(pe, n):
        if s[i] == "1":
            ans.append("*")
        else:
            ans.append("+")
        ans.append(s[i])
        
    expression = "".join(ans)
    return int(eval(expression))

for _ in range(int(input())):
    n = int(input())
    s = input()
    if len(s) == 2:
        print(int(s))
    elif len(s) == 3:
        pair1 = int(s[:2])
        pair2 = int(s[1:])
        if pair1 < pair2:
            print(min(pair1 * int(s[2]), pair1 + int(s[2])))
        else:
            print(min(pair2 * int(s[0]), pair2 + int(s[0])))
    else:
        print(fn(n, s))
