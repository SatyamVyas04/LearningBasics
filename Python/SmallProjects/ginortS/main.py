str1 = input()

s_lower = []
s_upper = []
s_digit_odd = []
s_digit_even = []

for i in str1:
    if i.islower():
        s_lower.append(i)
        s_lower.sort()

    if i.isupper():
        s_upper.append(i)
        s_upper.sort()

    if i.isdigit():
        if eval(i) % 2 != 0:
            s_digit_odd.append(i)
            s_digit_odd.sort()
        if eval(i) % 2 == 0:
            s_digit_even.append(i)
            s_digit_even.sort()

final = s_lower + s_upper + s_digit_odd + s_digit_even
print("".join(final))
