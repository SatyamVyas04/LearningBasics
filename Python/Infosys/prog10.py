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
maxfreq = 0 
max_repeating_word = "" 

for i in range(len(values)):
    current_value = values[i]
    current_word = keys[i]
    if current_value>maxfreq:
        maxfreq = current_value
        max_repeating_word = current_word
    elif current_value == maxfreq:
        if len(current_word)>len(max_repeating_word):
            maxfreq = current_value
            max_repeating_word = current_word
        
ansfreq = maxfreq
answord = max_repeating_word
print(answord, ansfreq)