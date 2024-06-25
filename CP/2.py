def fn(x, y, k):
    current_x = x
    seen = set()
    found_cycle = False

    lastidx = 0
    for _ in range(k):
        lastidx = _
        current_x += 1
        while current_x % y == 0:
            current_x //= y
        
        if current_x in seen:
            found_cycle = True
            break
        seen.add(current_x)
    
    if found_cycle:
        cycle_length = len(seen) - list(seen).index(current_x)
        remaining_operations = (k - lastidx - 1) % cycle_length
        for _ in range(remaining_operations):
            current_x += 1
            while current_x % y == 0:
                current_x //= y
    
    return current_x

for _ in range(int(input())):
    x, y, k = list(map(int, input().split()))
    print(fn(x, y, k))
