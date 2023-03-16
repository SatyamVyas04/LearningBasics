# N digit number generator
import random

n = int(input('Enter "n" to get a random N digit random integer: '))

start_at = 10 ** (n-1)
endpoint = 10 ** n
int_random = random.randrange(start_at, endpoint, 1)

print(f'Random {n} digit(s) number is:', int_random)
