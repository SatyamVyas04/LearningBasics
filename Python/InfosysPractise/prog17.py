def close_number(a, b, c):       
    if abs(a-b) == 1:
        if abs(a-c) >= 2 and abs(b-c)>=2:
            return True
    if abs(b-c) == 1:
        if abs(a-b) >= 2 and abs(a-c)>=2:
            return True
    if abs(c-a) == 1:
        if abs(a-b) >= 2 and abs(b-c)>=2:
            return True
    return False

print(close_number(5, 6, 7))



