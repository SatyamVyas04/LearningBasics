# Bubble Sorting the Efficient way
def BubbleSort(ar):
    for i in range(len(ar) - 1):
        for j in range(len(ar) - 1 - i):
            if ar[j] > ar[j+1]:
                ar[j], ar[j+1] = ar[j+1], ar[j]
    print(ar)
            
d1 = {"a":10, "b":2, "c":4}
BubbleSort(list(d1.values()))