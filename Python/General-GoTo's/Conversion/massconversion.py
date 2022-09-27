def kgtotonne():
    try:
        data = float(input('KilogramToTonne: Enter Mass (Kilograms): '))
        print(f'>> {data} Kilogram(Kg) = {data/1000} Tonne(Tn)')
    except ValueError:
        print('Invalid Input.')
    except KeyboardInterrupt:
        print('Keyboard Interrupt.')
    except OverflowError:
        print('Overflow Error: Numbers are too big to be converted from one form to another')
    except ZeroDivisionError:
        print("Division by Zero can't be performed (Think of dividing 1 cookie among 0 people...)")


def tonnetokg():
    try:
        data = float(input('TonneToKilogram: Enter Mass (Tonnes): '))
        print(f'>> {data} Tonne(Tn) = {data*1000} Kilogram(Kg)')
    except ValueError:
        print('Invalid Input.')
    except KeyboardInterrupt:
        print('Keyboard Interrupt.')
    except OverflowError:
        print('Overflow Error: Numbers are too big to be converted from one form to another')
    except ZeroDivisionError:
        print("Division by Zero can't be performed (Think of dividing 1 cookie among 0 people...)")


def kgtopound():
    try:
        data = float(input('KilogramToPound: Enter Mass (Kilograms): '))
        print(f">> {data} Kilogram(Kg) = {round(data*2.2046228, 5)} Pound(lbs)")
    except ValueError:
        print('Invalid Input.')
    except KeyboardInterrupt:
        print('Keyboard Interrupt.')
    except OverflowError:
        print('Overflow Error: Numbers are too big to be converted from one form to another')
    except ZeroDivisionError:
        print("Division by Zero can't be performed (Think of dividing 1 cookie among 0 people...)")


def poundtokg():
    try:
        data = float(input('PoundToKilogram: Enter Mass (Pound): '))
        print(f'>> {data} Pound(lbs) = {round(data/2.2046228, 5)} Kilogram(Kg)')
    except ValueError:
        print('Invalid Input.')
    except KeyboardInterrupt:
        print('Keyboard Interrupt.')
    except OverflowError:
        print('Overflow Error: Numbers are too big to be converted from one form to another')
    except ZeroDivisionError:
        print("Division by Zero can't be performed (Think of dividing 1 cookie among 0 people...)")


def kgtoounce():
    try:
        data = float(input('KilogramToOunce: Enter Mass (Kilogram): '))
        print(f">> {data} Kilogram(Kg) = {data*35.27399} Ounce(oz)")
    except ValueError:
        print('Invalid Input.')
    except KeyboardInterrupt:
        print('Keyboard Interrupt.')
    except OverflowError:
        print('Overflow Error: Numbers are too big to be converted from one form to another')
    except ZeroDivisionError:
        print("Division by Zero can't be performed (Think of dividing 1 cookie among 0 people...)")


def ouncetokg():
    try:
        data = float(input('OunceToKilogram: Enter Mass (Ounce): '))
        print(f'>> {data} Ounce(oz) = {data/35.27399} Kilogram(Kg)')
    except ValueError:
        print('Invalid Input.')
    except KeyboardInterrupt:
        print('Keyboard Interrupt.')
    except OverflowError:
        print('Overflow Error: Numbers are too big to be converted from one form to another')
    except ZeroDivisionError:
        print("Division by Zero can't be performed (Think of dividing 1 cookie among 0 people...)")


def poundtoounce():
    try:
        data = float(input('PoundToOunce: Enter Mass (Pound): '))
        print(f'>> {data} Pound(lbs) = {data*16} Ounce(oz)')
    except ValueError:
        print('Invalid Input.')
    except KeyboardInterrupt:
        print('Keyboard Interrupt.')
    except OverflowError:
        print('Overflow Error: Numbers are too big to be converted from one form to another')
    except ZeroDivisionError:
        print("Division by Zero can't be performed (Think of dividing 1 cookie among 0 people...)")


def ouncetopound():
    try:
        data = float(input('OunceToPound: Enter Mass (Ounce): '))
        print(f'>> {data} Ounce(oz) = {data/16} Pound(lbs)')
    except ValueError:
        print('Invalid Input.')
    except KeyboardInterrupt:
        print('Keyboard Interrupt.')
    except OverflowError:
        print('Overflow Error: Numbers are too big to be converted from one form to another')
    except ZeroDivisionError:
        print("Division by Zero can't be performed (Think of dividing 1 cookie among 0 people...)")


def Help_MassConvertor():
    print('Instructions for use: '
          '\n\t--- As soon as the converter function is called, the function asks for a value.'
          '\n\t--- Enter the asked value as per the given commands.'
          '\n\t--- The function will convert it to other desired value. '
          '\n\nAvailable Mass Converters are: '
          '\n> Kilograms to Tonne'
          '\n> Tonne to Kilograms'
          '\n> Kilograms to Pounds'
          '\n> Pounds to Kilograms'           
          '\n> Kilograms to Ounces'          
          '\n> Ounces to Kilograms'
          '\n> Pounds to Ounces'
          '\n> Ounces to Pounds')
