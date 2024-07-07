# D

def are_permutations_equal(array_size, perm1, perm2):
    hashmap = {perm2[index]: index for index in range(len(perm2))}
    size = array_size
    swap_count = 0

    for i in range(size):
        if perm1[i] != perm2[i]:
            swap_count += 1
            swap_index = hashmap[perm1[i]]
            perm2[i], perm2[swap_index] = perm2[swap_index], perm2[i]
            hashmap[perm2[swap_index]] = swap_index
            hashmap[perm1[i]] = i

    return swap_count % 2 == 0

def main():
    test_cases = int(input())

    for _ in range(test_cases):
        array_size = int(input())
        array_a = list(map(int, input().split()))
        array_b = list(map(int, input().split()))

        sorted_array_a = sorted(array_a)
        sorted_array_b = sorted(array_b)

        if sorted_array_a != sorted_array_b:
            print("NO")
        else:
            if are_permutations_equal(array_size, array_a, array_b):
                print("YES")
            else:
                print("NO")

if __name__ == "__main__":
    main()
