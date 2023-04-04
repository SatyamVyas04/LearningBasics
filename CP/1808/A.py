for _ in range(int(input())):
    a, b = map(int, input().split())
    m = int(max(list(str(a)))) - int(min(list(str(a))))
    n = a
    if b-a <= 100:
        tens = [i for i in range(a, b+1) if str(i).__contains__("0")]
        if len(tens)!=0:
            for i in tens:
                l = int(max(str(i)))
                if l >= m:
                    m = l
                    n = i
        else:
            for i in range(a, b+1):
                l = int(max(str(i))) - int(min(str(i)))
                if l >= m:
                    m = l
                    n = i
    else:
        tens = [i for i in range(b-100, b+1) if str(i).__contains__("0")]
        for i in tens:
            l = int(max(str(i)))
            if l >= m:
                m = l
                n = i
        
    print(n)