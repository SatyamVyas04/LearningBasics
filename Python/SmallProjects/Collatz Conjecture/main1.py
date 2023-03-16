from random import randint
n = randint(1, 100)
n = a = int(n)
max = n
print(str(max).rjust(10, "-"))
while True:
    if n%2 == 0:
        n = n/2
        print(f"{round(n)}".rjust(10, "-"))
        if n == 1:
            break
    if n%2 != 0:
        n = 3*n + 1
        print(f"{round(n)}".rjust(10, "-"))
        if n > max:
            max = n
        if n == 1:
            break

print("Start =", a)
print("Max =", round(max))

# Next task = Create a loop for the same
# Store values of Start and Max to find Largest Max wala Number :)
# NEW TASK: Learn Graphing and make graphs of this
# 3D GRAPHS BANANA HAI EKDUM MAST