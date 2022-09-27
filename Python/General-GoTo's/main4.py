# Phone Number Validity Checker
phone_number = input('Enter the Phone Number in DDD-DDD-DDDD format: ')
if phone_number[:3].isdigit() \
        and phone_number[4:7].isdigit() \
        and phone_number[8:].isdigit():

    if phone_number[3] and phone_number[7] == '-':
        print('Number is Valid')
    else:
        print('Missing Hyphens')
else:
    print('The number is invalid')
