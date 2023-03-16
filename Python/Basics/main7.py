# Nth Root Calculator

def nth_root(x, n='2'):
    nthroot = 1 / eval(n)
    answer = x ** nthroot
    print(answer)


try:
    print('Nth Root Calculator - Base^(1/N)')
    print('N must be an integer')
    base = float(input('ENTER BASE: '))
    root = (input('ENTER "N" to find the "Nth root" of the BASE: '))

    if root.isdigit():
        print('Answer: ')
        nth_root(base, root)
    else:
        print(f'Invalid input for "n". '
              f'\nTherefore, the default root (√) of {base} is equal to:')
        nth_root(base)

except ValueError:
    print('Invalid Input')
