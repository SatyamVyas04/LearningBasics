def wordsep(s):
    word = ""
    spc = ""
    for i in s:
        if ord(i) in range(65, 123):
            word+=i
        else:
            spc+=i
    return word+spc

s = input()
word = wordsep(s)
print(word)