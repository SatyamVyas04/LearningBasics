# Take a and b
# find number that satisfy these conditions

# # Conditions:
# 1) divisible by 15
# 2) Number = 2 digits => String -> length

# Add these to a list
# if len(list)==0: return -1
# else: find max

def valid(a, b): # Assumed that a<b
    l = []
    for i in range(a, b+1):
        if i%15==0 and len(str(i))==2:
            l.append(i)
    if len(l) == 0:
        return -1
    else:
        return max(l)

#driver
ansl = valid(10, 15)
print(ansl, "ANS")