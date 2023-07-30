vowels = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
string = input().split()

for index, word in enumerate(string):
    temp_vowels = ''
    temp_const = ''
    if index%2!=0:
        # EVEN POSITION
        for i in word:
            if i in vowels: 
                temp_vowels += i 
            elif i not in vowels:
                temp_const += i
        word = temp_const+temp_vowels
        string[index] = word
        
    elif index%2==0:
        # ODD POSITION 
        string[index] = word[::-1]
        
# string = list
print(" ".join(string))