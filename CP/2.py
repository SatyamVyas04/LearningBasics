def fn(matrix, n, m):
    new_matrix = [row[:] for row in matrix] 
    for i in range(n):
        for j in range(m):
            curr = matrix[i][j]
            top = matrix[i-1][j] if i > 0 else -1
            bottom = matrix[i+1][j] if i < n-1 else -1
            left = matrix[i][j-1] if j > 0 else -1
            right = matrix[i][j+1] if j < m-1 else -1
            if curr > left and curr > right and curr > top and curr > bottom:
                new_matrix[i][j] = max(left, right, top, bottom)
    return new_matrix

for _ in range(int(input())):
    n, m = map(int, input().split())
    matrix = []
    for i in range(n):
        matrix.append(list(map(int, input().split())))
    matrix = fn(matrix, n, m)
    for row in matrix:
        print(" ".join(map(str, row)))
