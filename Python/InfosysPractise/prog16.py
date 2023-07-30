def find_duplicates(l):
    arr = []
    
    d = {} ##### VERY VERY IMP 
    for i in l:
        if i not in d:
            d[i] = 1
        else:
            d[i] += 1
    
    for i in d:
        if d[i] > 1:
            arr.append(i)
    
    return arr
    
list_of_nums = [12, 54, 68, 759, 24, 15, 12, 68, 987, 758, 25, 69]
print(find_duplicates(list_of_nums))