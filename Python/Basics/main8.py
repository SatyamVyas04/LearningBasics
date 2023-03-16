# Arithmetic mean calculator
print('''Arithmetic Mean finder: 
-- First, Enter the smaller number 
-- Secondly, Enter greater number 
Result = Two equidistant points (AM's) between Number1 and Number2''')

num1 = int(input('Enter Number 1: '))
num2 = int(input('Enter Number 2: '))
d = float((num2 - num1)/3)
equi1 = round(num1 + d, 4)
equi2 = round(num1 + 2*d, 4)

print(f'Equidistant points are: {equi1} and {equi2}')
print(f'Therefore, the result becomes: {num1}, {equi1}, {equi2}, {num2}')
