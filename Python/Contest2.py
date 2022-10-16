def main(score):
    W = L = 0
    for i in score:
        if i == 1:
            W += 1
            if W==11 and L<=9:
                return "WIN"
        else:
            L += 1
            if L==11 and W<=9:
                return "LOSS"  
               
    if W-L >= 2:
        return "WIN"
    elif L-W >=2:
        return "LOSS"

for _ in range(int(input())):
    score = list(input())
    score = [eval(num) for num in score]
    print(main(score))