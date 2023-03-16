def patternbabu(n):
    for y in range(2*n-1):
        for x in range(2*n-1):
            if x + y>=n-1 and y-x<=n-1 and y+x<=3*(n-1) and x-y <= n-1:
                if x>=n-1:
                    print(f" {x-n+2} ", end="")
                if x<n-1:
                    print(f" {n-x} ", end="")
            else:
                print("   ", end="")
        print()

n = int(input("Enter N: "))
patternbabu(n)