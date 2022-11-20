# Input Style = N, K, x, y
# coordinates can be (0,0) to (n, n)
# K times hi hit hona chahiye
def main(n, k, x, y):
    if x == y:
        return f"({n}, {n})"
    if x > y:
        y += n - x
        x = n
        p1 = (x, y)
        p2 = (y, x)
        p3 = (0, n - y)
        p4 = (n - y, 0)
    if y > x:
        x += n - y
        y = n
        p1 = (x, y)
        p2 = (y, x)
        p3 = (n - x, 0)
        p4 = (0, n - x)
    k -= 1
    rem = k % 4
    if rem == 0:
        return p1
    if rem == 1:
        return p2
    if rem == 2:
        return p3
    if rem == 3:
        return p4


# Driver Program
for _ in range(int(input())):
    n, k, x, y = map(int, input().split())
    print(main(n, k, x, y))