import time
def Timer(func):
    def wrapper(*args):
        start = time.perf_counter_ns()
        x = func(*args)
        end = time.perf_counter_ns()
        print(f"{func.__name__} took {end-start} ns :: Args={args}")
    return wrapper

@Timer
def add(a):
    sum=0
    for i in range(1, a+1):
        sum+=i
    return sum

@Timer
def add2(a):
    return int(a*(a+1)/2)

add(10000000)
add2(10000000)