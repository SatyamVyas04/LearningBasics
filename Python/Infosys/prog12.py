def find_pairs(l, n):
    count = 0
    for i in range(0, len(l)-1):
        j = i+1
        while j<len(l):
            if l[i]+l[j]==n:
                count+=1
            j+=1
    return count

l = [1, 2, 7, 4, 5, 6, 0, 3]
num = 6
print(find_pairs(l, num))