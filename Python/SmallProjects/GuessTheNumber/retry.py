from random import randint
num = randint(1, 100)
guesses = 10
closest = 0
print("GUESS THE NUMBER GAME: ")
while guesses>0:
    g = int(input(f"=> Enter your {11 - guesses} guess: "))
    # Break Case
    if g==num:
        print("\n=> Correct Guess!!!")
        break
    
    # Difference
    diff = abs(num-g)
    
    # Until a warm is found
    if closest == 0: 
        if diff<=10:
            print("--> WARM!")
            closest = diff
        else:
            print("--> COLD!")
        guesses-=1
        continue 
        
    
    # For subsequent guesses
    if diff<closest:
        print("--> WARMER!")
    else:
        print("--> COLDER!")
    guesses-=1
else:
    print(f"\n=> Oh No! You ran out of guesses...")
    print(f"=> The Correct Ans was {num}")
    