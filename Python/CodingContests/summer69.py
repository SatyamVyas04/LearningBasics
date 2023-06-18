def Summer69(l):
    flag = False #jab tak 6 nahi mila
    s = 0
    sixcount = l.count(6)
    ninecount = l.count(9)
    if sixcount>0 and ninecount>0:
        for i in l:
            if flag == False:
                if i==6 and ninecount>0:
                    sixcount-=1
                    flag = True
                elif i==9:
                    ninecount-=1
                    s += i
                else:
                    s+=i
            else:
                if i==9:
                    ninecount-=1
                    flag = False
        return s
    else:
        return sum(l)
    
    
print(Summer69([1, 2, 3, 4, 6, 10, 12, 9]))
print(Summer69([1, 2, 6, 4, 3, 2, 9, 1, 3, 4]))
print(Summer69([1, 2, 6, 9, 9]))
print(Summer69([1, 2, 6, 7, 9, 6, 1]))
print(Summer69([1, 2, 6, 6, 9, 9, 6]))
print(Summer69([6]))
print(Summer69([9]))