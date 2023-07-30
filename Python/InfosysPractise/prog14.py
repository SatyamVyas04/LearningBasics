def palind(s):
    s = s.lower()
    if s[0]!=s[-1]:
        return False
    elif len(s)<=1:
        return True
    else:
        return palind(s[1:-1])

s = "MadAMa"
call = palind(s)
if call:
    print("YES")
else:
    print("NO")