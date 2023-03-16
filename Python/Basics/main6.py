months = {'January': '31', 'February': '28', 'March': '31',
          'April': '30', 'May': '31', 'June': '30',
          'July': '31', 'August': '31', 'September': '30',
          'October': '31', 'November': '30', 'December': '31'}

# Feature 1 -------------------------------------------------------------------------------
print('\n>>> List of all month in alphabetical order:')
for i in sorted(months.keys()):
    print(f'> {i}')

# Feature 2 -------------------------------------------------------------------------------
list_30days = ['February']
list_31days = []
for i in months:
    if months[i] == '30':
        list_30days.append(i)
    if months[i] == '31':
        list_31days.append(i)
list_30days.extend(list_31days)
print('\n>>> List of all <Month><Days in it> arranged on the basis of the number of days: ')
for i in list_30days:
    print('>', i, months.get(i))

# Feature 3 ---------------------------------------------------------------------------------
user_input = input('Enter a month to know the number of days it contains: ')
print('\n>>> Number of days in the entered month =', months.get(user_input.title()))

# Feature 4 ---------------------------------------------------------------------------------
list_1 = []
print()
n = (input('Enter 28, 30, 31 to know the months that contain these many days: '))
for i in months:
    if months.get(i) == n:
        list_1.append(i)
print(f'\n>>> The months that contain {n} days are:')
for i in list_1:
    print(f'> {i}')
