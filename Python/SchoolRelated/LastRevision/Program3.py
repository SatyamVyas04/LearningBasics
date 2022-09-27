# Program to add n strings to a list <Capitalized>
list_1 = []
n = int(input('Enter number of strings you want to enter: '))
for i in range(0, n):
    x = str(input(f'Enter string {i + 1}: '))
    list_1.append(x.capitalize())
print(f'{list_1} is the list you are looking for...')
