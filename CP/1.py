# A
def int_inp():
    """
    Reads an integer input.
    """
    return int(input())

def int_list_inp():
    """
    Reads a list of integers from a single line of input.
    """
    return list(map(int, input().split()))

def matrix_inp(n):
    """
    Reads a matrix of size n x m from input.
    """
    matrix = []
    for _ in range(n):
        matrix.append(list(map(int, input().split())))
    return matrix

def matrix_inp_nbsp(n):
    """
    Reads a matrix of size n x m from input without spaces between elements.
    """
    matrix = []
    for _ in range(n):
        matrix.append(list(map(int, list(input().strip()))))
    return matrix

def print_many(*args):
    """
    Prints multiple arguments separated by spaces.
    """
    print(" ".join(map(str, args)))
    
def space_join(arr):
    """
    Joins a list of integers into a single string separated by spaces.
    """
    return " ".join(map(str, arr))

def solve():
    """
    The main logic for solving a given problem.
    """
    pass

def main():
    """
    Main function to handle multiple test cases.
    """
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
