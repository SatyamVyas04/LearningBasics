# Write a program that takes in 2 elements and generates series with two equidistant point
[a, b] = list(map(float, input().split(", ")))
d = round(((b-a)/3), 3)
print("The Equidistant points are as follows:", f"{a}, {a+d}, {a+2*d}, {b}")
