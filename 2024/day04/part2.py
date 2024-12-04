def check_diag1(i,j):
    return (matrix[i - 1][j - 1] == 'S' and matrix[i + 1][j + 1] == 'M') or (matrix[i - 1][j - 1] == 'M' and matrix[i + 1][j + 1] == 'S')

def check_diag2(i,j):
    return (matrix[i - 1][j + 1] == 'S' and matrix[i + 1][j - 1] == 'M') or (matrix[i - 1][j + 1] == 'M' and matrix[i + 1][j - 1] == 'S')

def check_for_xmas(i, j):
    return (check_diag1(i, j) and check_diag2(i, j))

file = open("input.txt")
matrix = [[el for el in line] for line in file.readlines()]

cols = len(matrix[0]) - 1
rows = len(matrix)

sum = 0

for i in range(1, rows - 1):
    for j in range(1, cols - 1):
        if matrix[i][j] == 'A':
            if check_for_xmas(i, j):
                sum += 1

print(sum)