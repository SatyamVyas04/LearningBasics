vowels = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]

def sms_encoding(s):
    s = s.split()
    ans = []
    for word in s:
        vowel_count = 0
        for ch in word:
            if ch in vowels:
                vowel_count+=1
        if len(word) == vowel_count:
            ans.append(word)
        else:
            wordwithoutvowel = ""
            for ch in word:
                if ch not in vowels:
                    wordwithoutvowel += ch
            ans.append(wordwithoutvowel)
            
    return " ".join(ans)

# driver
st = "I will not repeat mistakes"
a = sms_encoding(st)
print(a)