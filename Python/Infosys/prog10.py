from collections import Counter
# driver
s = "Work like you do not need money love like you have never been hurt and dance like no one is watching"
arr = s.split()
count = {}
for i in arr:
    if i in count.keys():
        count[i] += 1
    else:
        count[i] = 1
        
keys = list(count.keys())
values = list(count.values()) 
maxval = 0 
anskey = "" 
for i in range(len(values)):
    current_value = values[i]
    current_word = keys[i]
    if current_value>maxval:
        maxval = current_value
        anskey = current_word
    elif current_value == maxval:
        if len(current_word)>len(anskey):
            maxval = current_value
            anskey = current_word
        else:
            pass
        
ansfreq = maxval
answord = anskey
print(answord, ansfreq)