import collections
import statistics
import math

for _ in range(int(input())):
    n = int(input())
    s = input()
    pairs = adjpairs = 0
    for i in range(n - 2):
        if s[i] == s[i + 1]:
            pairs += 1
        if s[i] == s[i + 1] and s[i + 1] == s[i + 2]:
            adjpairs += 1
    if s[-1] == s[-2]:
        pairs += 1

    print(pairs, adjpairs)

    if s.count("1") == n or s.count("0") == n:
        print("YES")
    else:
        if pairs and adjpairs % 2 == 0:
            pass
        # Tough toh hai :Sob:
        # ADJFLIP