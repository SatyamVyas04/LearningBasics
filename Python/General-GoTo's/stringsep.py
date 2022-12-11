letters = ["a", "b", "c", "d", "e", "f", 
           "g", "h", "i", "j", "k", "l", 
           "m", "n", "o", "p", "q", "s", 
           "t", "u", "u", "v", "w", "x", 
           "y", "z"]

def wordsep(s):
    word = ""
    special = ""
    for i in s:
        if i.lower() in letters:
            word+=i
        else:
            special += i
    return word+special

s = input()
word = wordsep(s)
print(word)