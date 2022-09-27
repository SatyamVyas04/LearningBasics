# Pattern printing (a, bb, ccc, dddd)
l1 = []
for i in range(1, 27):
    x = 64 + i
    print(chr(x) * i)
    l1.append(chr(x) * i)
print(l1)
