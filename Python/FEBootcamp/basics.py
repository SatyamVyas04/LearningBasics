from random import randint
num = randint(1, 100)
guesses = 10
closest = 0
print("GUESS THE NUMBER GAME: ")
while guesses>0:
    g = int(input(f"=> Enter your {11 - guesses} guess: "))
    # Break Case
    if g==num:
        print("=> Correct Guess!!!")
        break
    
    # Difference
    diff = abs(closest-g)
    
    # Until a warm is found
    if closest == 0: 
        if diff<=10:
            print("--> WARM!")
            closest = diff
        else:
            print("--> COLD!")
        continue 
        
    
    # For subsequent guesses
    if diff<closest:
        print("--> WARMER!")
    else:
        print("--> COLDER!")
    guesses-=1