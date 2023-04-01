# Beautiful Sequence
def sol():
    n = int(input())
    nums = [-1]
    nums += list(map(int, input().split()))
    for i in range(1, n+1):
        if nums[i] <= i:
            return "YES"
    return "NO"
    

for  _ in range(int(input())):
    print(sol())
    
    # ACCEPTED :)