ones = {"1":"one", "2":"two", "3":"three", "4":"four",
        "5":"five", "6":"six", "7":"seven", "8":"eight",
        "9":"nine"}
middle = {}
tens = {"10":"ten", "20":"twenty", "30":"thirty", "40":"forty",
        "50":"fifty", "60":"sixty", "70":"seventy",
        "80":"eighty", "90":"ninety"}

def int_to_eng(n):
    s = str(n)
    l = len(s)
    if s=="1000":
        return "One Thousand"
    if l>=4:
        return -1
    #abc
    a = eval(s[0])
    b = eval(s[1])
    c = eval(s[2])

# 001 ==> a = 0, b = 0, c==> ones[c]
# 011 ==> a = 0, ==> middle[bc]
# 020 ==> a=0 and c = 0 ==> tens[bc]
# 200 ==> b == 0 and c == 0 ==> ones[a] hundred
# 201 ==> b == 0 ==> ones[a] hundreds and ones[c]
# 215 ==> no one is zero ==> ones[a] hundreds and middle[bc]
# 221 ==> noone is zero ==> ones[a] hundred and tens[bc] and ones[c]
    
num = 125
print(int_to_eng(num))