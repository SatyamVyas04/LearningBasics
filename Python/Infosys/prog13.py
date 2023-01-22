def odd(l):
    arr = []
    for i in l:
        if i%2!=0:
            arr.append(i)
    return arr

def even(l):
    arr = []
    for i in l:
        if i%2==0:
            arr.append(i)
    return arr

def sumof(l, fil=None):
    s = 0
    if fil==None:
        return sum(l)
    if fil=="odd":
        list_odd = odd(l)
        return sum(list_odd)
    if fil=="even":
        list_even = even(l)
        return sum(list_even)

sampledata = range(1, 11)
print(sumof(sampledata, "even"))