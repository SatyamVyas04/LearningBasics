from primePy import primes
l = []
for i in range(1, 2001):
    l.append(i)

l2 = []
for i in range(len(l)):
    if l[i]%2==0:
        continue
    elif l[i]%3==0:
        continue
    elif l[i]%5==0:
        continue
    elif l[i]%7==0:
        l2.append(l[i]//7)
        
print(l2)
print(l2.__len__())
print(primes.first(76))

## DSGT SETS PROBLEMS DONE