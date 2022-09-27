try:
    import random
    print('''\n>>> Welcome to Guess-The-Number Game
    A Random Number from Start Point to End Point has been set.
    Try to 'Guess' it within 5 steps
    All the Best !!!\n''')
    starting_point = int(input('Enter the Start Point for the Program: '))
    end_point = int(input('Enter the End Point for the Program: '))
    x = random.randint(starting_point, end_point)

    for i in range(1, 6):
        guess = int(input(f">>> Attempt {i}: "))
        if guess < x:
            print('Higher...')
        if guess > x:
            print('Lower...')
        if guess == x:
            print('\nCorrect! Good Job... ')
            print('Game Completed')
            print('Thank you for Playing!')
            quit(code=0)

    print('\nOh no! Out of Attempts.')
    print(f'The NUMBER WAS {x}')
    print('Game Over')
    print('Thank you for Playing!')

except ValueError:
    print('Input Error.')
    print('Only Numbers are to be guessed')
    print('Game Over')
    print('Thank you for Playing!')
