def fn(n, s):
    def sol(ps, pe, pair):
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
    
    if "0" in s:
        return 0
    
    curr_sol = float("inf")
    
    for r in range(2, n+1):
        l = r - 2
        pair = int(s[l:r])
        curr_sol = min(curr_sol, sol(l, r, pair))

    return curr_sol
    

for _ in range(int(input())):
    n = int(input())
    s = input()
    if len(s) == 2:
        print(int(s))
    elif len(s) == 3:
        pair1 = int(s[:2])
        pair2 = int(s[1:])
        a = min(pair1 * int(s[2]), pair1 + int(s[2]))
        b = min(pair2 * int(s[0]), pair2 + int(s[0]))
        ans = min(a, b)
        print(ans)
    else:
        print(fn(n, s))
