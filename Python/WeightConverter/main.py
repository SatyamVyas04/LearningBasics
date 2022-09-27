weight = input('Weight: ')
unit = input('(L)bs or (K)gs: ')
if unit.upper() == "L":
    converted = int(weight) * 0.45
    print('Your weight in Kg is :', converted)
elif unit.upper() == "K":
    converted = int(weight) * 2.20
    print('Your weight in Lbs is :', converted)
else:
    print('ERROR')