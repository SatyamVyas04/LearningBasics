# Fibonacci series till n terms
n = int(input())
f_s = [0, 1]
for i in range(n):
    x = f_s[i] + f_s[i+1]
    f_s.append(x)
print(f_s)
