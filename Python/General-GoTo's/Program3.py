# Word Reverser
print("\n", "Welcome to Word Reverser".center(90, "-"))
string = input("\n--> Enter the Text you want to Reverse: ")

stack = []
for i in string:
    stack.append(i)

type = int(input("--> Select Case for the Reversed Text\n\
    Enter 1 for 'same as input'\n\
    Enter 2 for 'Capitalised'\n\
    Enter 3 for 'Title Case'\n\
    Enter 4 for 'Lower Case'\n\
    Enter your choice: "))

if 1 <= type <= 4:
    print("\n--> Reversed Text: ", end="")
    rev_text = ""
    for _ in range(len(stack)):
        rev_text += stack.pop()
    if type == 1:
        print(rev_text)
    if type == 2:
        print(rev_text.upper())
    if type == 3:
        print(rev_text.title())
    if type == 4:
        print(rev_text.lower())
else:
    print("\n--> Invalid Input ".ljust(90, "X"))
print("\n", "Thank you for using the text reverser...".center(90, "-"), "\n")