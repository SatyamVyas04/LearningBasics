def fn(x, y):
    xorval = x ^ y
    length = 1
    while not xorval % 2:
        xorval >>= 1
        length <<= 1
    return length


for _ in range(int(input())):
    x, y = map(int, input().split())
    print(fn(x, y))