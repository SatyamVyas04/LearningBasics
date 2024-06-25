def fn(arr, cards):
    n, l, r = arr
    ans = 0
    curr = 0
    left = 0
    for right in range(n):
        if cards[right] in range(l, r + 1):
            left = right
            curr = 0
            ans += 1
        else:
            curr += cards[right]
            if curr in range(l, r + 1):
                ans += 1
                left = right
                curr = 0
            else:
                while curr > r:
                    curr -= cards[left]
                    left += 1
    return ans


for _ in range(int(input())):
    arr = list(map(int, input().split()))
    cards = list(map(int, input().split()))
    print(str(fn(arr, cards)))
