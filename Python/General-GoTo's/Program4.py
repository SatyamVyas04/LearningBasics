# Program to find a number in the list and then find it positions
list1 = list(eval(input('Enter a list: ')))
x = eval(input('Enter an element to know its position in the entered list: '))
if x in list1:
    print(f'Yes, This number is in the list at {list1.count(x)} places')
    positions = []
    for j in range(list1.count(x)):
        positions.append(list1.index(x))
        list1.insert(list1.index(x), 'a')
        list1.remove(x)
    print(f'This Number is present at {positions} place(s)---[index given]')
else:
    print('Sorry, This number is not in the list')

