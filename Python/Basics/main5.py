# Words-In-Paragraph calculator

x = input('Enter a Sentence: ')
y = list(x.split(' '))
list_alnum = 0

for i in x:
    if i.isalnum():
        list_alnum += 1
    else:
        pass

print('\nSentence:', x.title())
print('\n>>> Statistics of this sentence: ')
print('>', len(y), 'words (contained within spaces)')
print('>', len(x), 'letters (including spaces and punctuations)')
print('>', list_alnum/len(x)*100, 'is the %age of Alpha-Numeric Characters')
