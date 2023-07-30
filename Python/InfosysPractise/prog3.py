# Basic approach

l = list(input()) 
count_dict = {}
for i in l:
    if i in count_dict.keys():
        count_dict[i] += 1 #add 1 if present already
    else:
        count_dict[i] = 1 
        
list_letters = sorted(count_dict.keys())
for i in list_letters:
    print(f"{count_dict[i]}{i}", end="")
