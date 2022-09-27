# Binary Search
def BinarySearch(ar, e, l, h):
    while l <= h:
        m = int(l + (h-l)/2)
        if ar[m] == e:
            return m
        if ar[m] < e:
            l = m + 1
        else: 
            h = m - 1
    return -1

array = list(map(int, input().strip().split()))
array.sort()
x = 8
result = BinarySearch(array, x, 0, len(array) - 1)

if result != -1:
    print("THE ELEMENT IS PRESENT AT INDEX", str(result))
else:
    print("NOT PRESENT IN THE LIST")