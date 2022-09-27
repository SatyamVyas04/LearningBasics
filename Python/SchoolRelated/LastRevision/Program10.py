# Check if a number is Perfect, Armstrong or Palindrome]
number = int(input())
# Armstrong Check
temp = number
sum = 0
while temp > 0:
    digit = temp % 10
    sum += digit ** 3
    temp //= 10
if sum == number:
    print(f'{number} IS AN ARMSTRONG NUMBER')
else:
    print(f'{number} is not an armstrong number')

# Perfect Check
sum = 0
for i in range(1, number):
    if number % i == 0:
        sum += i
if sum == number:
    print(f'{number} IS A PERFECT NUMBER')
else:
    print(f'{number} is not a perfect number' )

# PALINDROME CHECK
string = str(number)
if string == string[::-1]:
    print(f'{number} IS A PALINDROME')
else:
    print(f'{number} is not a palindrome')