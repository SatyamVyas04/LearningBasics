s1 = list("I like Python")
s2 = list("Java is a very popular language") 

# keep unique
a = []
b = []
for i in s1:
    if i!=" ":
        if i not in a:
            a.append(i)

for i in s2:
    if i!=" ":
        if i not in b:
            b.append(i)

d = {}
print(a)
print(b)


for i in a:
    if i not in d.keys():
        d[i] = 1
    else:
        d[i] += 1
        
for i in b:
    if i not in d.keys():
        d[i] = 1
    else:
        d[i] += 1
        
for i in d.keys():
    if d[i]==2:
        print(i, end="")