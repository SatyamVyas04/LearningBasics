# B

def fn(matrix1, matrix2, n, m):
    for i in range(n - 1):
        for j in range(m - 1):
            diff =  (matrix2[i][j] - matrix1[i][j] + 3) % 3
            if diff != 0:
                matrix1[i][j] = (matrix1[i][j] + diff)%3
                matrix1[i+1][j+1] = (matrix1[i+1][j+1] + diff)%3
                matrix1[i][j+1] = (matrix1[i][j+1] + 3 - diff)%3
                matrix1[i+1][j] = (matrix1[i+1][j] + 3 - diff)%3
    
    for i in range(n):
        for j in range(m):
            if matrix1[i][j] != matrix2[i][j]:
                return "NO"
    return "YES" 
                
                
for _ in range(int(input())):
    n, m = map(int, input().split())
    matrix1 = []
    for i in range(n):
        matrix1.append(list(map(int, list(input()))))
    matrix2 = []
    for i in range(n):
        matrix2.append(list(map(int, list(input()))))

    if matrix1 == matrix2:
        print("YES")
    else:
        print(fn(matrix1, matrix2, n, m))
