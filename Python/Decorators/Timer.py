import time
def Timer(func):
    def wrapper(*args):
        start = time.perf_counter_ns()
        # x = list(func(*args))
        end = time.perf_counter_ns()
        print(f"{func.__name__} took {end-start} ns :: Args={args}")
        # print(f"{x}\n")
    return wrapper

def square(n):
    return n*n

@Timer
def squaringlist(l):
    return map(square, l)

@Timer
def squaringlist2(l):
    return [i**2 for i in l]

squaringlist(range(100000))
squaringlist2(range(100000))

# Shows mapping is faster than using a comprehension
# as mapping creates an iterator, not iterable.