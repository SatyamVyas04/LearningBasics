# Program to check whether a number is divisible by another number
try:
    number_1 = int(input('Enter Number1: '))
    number_2 = int(input('Enter Number2: '))
    if number_1 % number_2 == 0:
        print('Number 1 is DIVISIBLE by Number 2')
        print('The Quotient is:', number_1//number_2)
    else:
        print('Number 1 is NOT DIVISIBLE by Number 2')

except ValueError:
    print('Input error!'
          '\nThis Program only accepts Integers')

