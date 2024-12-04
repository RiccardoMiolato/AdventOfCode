def check_diagonals(i, j):
    word = ['X', 'M', 'A', 'S']
    count = 0

    if i - 3 >= 0 and j - 3 >= 0:
        for k in range(1, 4):
            if matrix[i - k][j - k] != word[k]:
                break

            if k == 3:
                count += 1


    if i - 3 >= 0 and j + 3 < cols:
        for k in range(1, 4):
            if matrix[i - k][j + k] != word[k]:
                break

            if k == 3:
                count += 1


    if i + 3 < rows and j - 3 >= 0:
        for k in range(1, 4):
            if matrix[i + k][j - k] != word[k]:
                break

            if k == 3:
                count += 1


    if i + 3 < rows and j + 3 < cols:
        for k in range(1, 4):
            if matrix[i + k][j + k] != word[k]:
                break

            if k == 3:
                count += 1

    return count

def check_horizontal(i, j):
    word = ['X', 'M', 'A', 'S']
    count = 0

    if j - 3 >= 0:
        for k in range(1, 4):
            if matrix[i][j - k] != word[k]:
                break

            if k == 3:
                count += 1

    if j + 3 < cols:
        for k in range(1, 4):
            if matrix[i][j + k] != word[k]:
                break

            if k == 3:
                count += 1

    return count

def check_vertical(i, j):
    word = ['X', 'M', 'A', 'S']
    count = 0

    if i - 3 >= 0:
        for k in range(1, 4):
            if matrix[i - k][j] != word[k]:
                break

            if k == 3:
                count += 1

    if i + 3 < rows:
        for k in range(1, 4):
            if matrix[i + k][j] != word[k]:
                break

            if k == 3:
                count += 1

    return count


def check_for_xmas(i, j):
    count = 0

    count += check_diagonals(i, j)
    count += check_horizontal(i, j)
    count += check_vertical(i, j)

    return count

file = open("input.txt")
matrix = [[el for el in line] for line in file.readlines()]

cols = len(matrix[0]) - 1
rows = len(matrix)

sum = 0

for i in range(rows):
    for j in range(cols):
        if matrix[i][j] == 'X':
            sum += check_for_xmas(i, j)

print(sum)