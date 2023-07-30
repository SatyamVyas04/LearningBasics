s = "3523014"
temp = []
for i in range(len(s)): # 0 se leke n-1 nth index tak
    j = i+1 # 1 se leke n take
    while j<=len(s):
        subs = list(s[i:j])
        subs2 = list(map(int, subs))
        if sum(subs2)==10:
            temp.append("".join(subs))
        j+=1
        
print(temp)

# i, j
# 0, 1
# 0, 2
# ...
# 0, n
# 1, 2 # so that we don't get 1, 0 again