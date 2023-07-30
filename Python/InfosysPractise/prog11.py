l = [1, 2, 2, 3, 5, 4, 2, 2, 1, 2]
n = 2
indexes = []
allindexes = list(range(len(l)))
for index, number in enumerate(l):
    if number == n:
        indexes.append(index)

forbidden_indexes = []

for num in indexes:
    aage = num+1
    peeche = num-1
    forbidden_indexes.append(peeche)
    forbidden_indexes.append(num)
    forbidden_indexes.append(aage)

# removing the possibility of getting <0 indexes and >n indexes
forbidden_indexes = list(set(forbidden_indexes)) # remove duplicate
forbidden_indexes = [i for i in forbidden_indexes if i>=0 and i<len(l)]

indexes = forbidden_indexes # simplifying

set_missing = set(allindexes) - set(indexes)

s = 0
for i in set_missing:
    s+=l[i]
    
print(s)

# line 10 ke baad
# apan indexes se ek number utha rele hain, aage peeche leke, forbidden_indexes main daal lere hain