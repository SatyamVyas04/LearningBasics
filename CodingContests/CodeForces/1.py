for _ in range(int(input())):
    for i in range(3):
        s = set(input())
        if "?" in s:
            s = {"A", "B", "C"}.difference(s) 
            ans = s
        else:
            pass
    print(list(ans)[0])