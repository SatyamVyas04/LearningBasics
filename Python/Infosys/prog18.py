# all factors are found before root
def check(a, b):
    arr = []
    for i in range(a, b+1):
        j = i+1
        while j<=b:
            if j%i==0:
                arr.append(j)
            j+=1
    arr = list(set(arr))
    return [arr, len(arr)]

print(check(10, 30))