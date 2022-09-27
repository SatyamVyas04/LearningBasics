class Date:
    def __init__(self, d, m, y):
        self.d = d
        self.m = m
        self.y = y


monthDays = [31, 28, 31, 30, 31, 30,
             31, 31, 30, 31, 30, 31]


def count_leap_years(d):
    years = d.y
    if d.m <= 2:
        years -= 1
    return int(years / 4) - int(years / 100) + int(years / 400)


def getDifference(date_1, date_2):
    n1 = date_1.y * 365 + date_1.d
    for i in range(0, date_1.m - 1):
        n1 += monthDays[i]
    n1 += count_leap_years(date_1)
    n2 = date_2.y * 365 + date_2.d
    for i in range(0, date_2.m - 1):
        n2 += monthDays[i]
    n2 += count_leap_years(date_2)
    return n2 - n1


# Driver program
x1 = int(input('DD1: '))
y1 = int(input('MM1: '))
z1 = int(input('YYYY1: '))
dt1 = Date(x1, y1, z1)
print(f'DATE 1 is {x1}/{y1}/{z1}')
x2 = int(input('\nDD2: '))
y2 = int(input('MM2: '))
z2 = int(input('YYYY2: '))
dt2 = Date(x2, y2, z2)
print(f'DATE 2 is {x2}/{y2}/{z2}')
X = getDifference(dt1, dt2)
Y = X * 24
Z = Y * 60
Z_2 = Z * 60
print("\nTHE STATISTICS:")
print('Number of Days:', X)
print('Number of Hours as of 12 midnight:', Y)
print('Number of Minutes as of 12 midnight:', Z)
print('Number of Seconds as of 12 midnight :', Z_2)
