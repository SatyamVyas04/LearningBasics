from collections import Counter
# driver
s = "Work like you do not need money love like you you never been hurt and dance like no one is watching"
arr = s.split()
count = {}
for i in arr:
    if i in count.keys():
        count[i] += 1
    else:
        count[i] = 1

values = list(count.values())
maxvalue = max(values)
lambaword = ""

for word, freq in count.items():
    if freq == maxvalue:
        if len(word)>=len(lambaword):
            lambaword=word
    
print(lambaword, maxvalue)