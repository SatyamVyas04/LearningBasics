def fact(n):
    if n == 1:
        return n
    elif n > 1:
        print(n)
        return n*fact(n-1)
    else:
        return "Factorial does not exist for negative numbers"

print(fact(10))