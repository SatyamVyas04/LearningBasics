# Lucky Numbers
for _ in range(int(input())):
    start, end = map(int, input().split())
    tens = [i for i in range(start, end) if str(i).__contains__("0")]
    m = int(max(str(start))) - int(min(str(start)))
    n = start
    if len(tens)!=0:
        for num in tens:
            dma = 0
            i = num
            while num > 0:
                digit = num % 10
                if digit>=dma:
                    dma = digit
                num //= 10
            luck = dma
            if luck >= m:
                m = luck
                n = i
    elif len(tens)==0:
        for num in range(start, end+1):
            dma = 0
            dmi = 9
            i = num
            while num > 0:
                digit = num % 10
                if digit>=dma:
                    dma = digit
                if digit<=dmi:
                    dmi = digit
                num //= 10
            luck = dma - dmi
            if luck >= m:
                m = luck
                n = i
    print(n)
    
    # TLE on TEST 2