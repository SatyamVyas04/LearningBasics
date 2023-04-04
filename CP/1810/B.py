# Candies
for _ in range(int(input())):
    n = bin(int(input()))
    b = int(str(n)[2:])
    last = b%10
    if last==0:
        print("-1")
    else: 
        b//=10
        b = str(b)
        ans = []
        for i in b:
            ans.append(f"{int(i)+1}")
        print(len(ans))
        print(" ".join(ans))
        
    # ACCEPTED :)