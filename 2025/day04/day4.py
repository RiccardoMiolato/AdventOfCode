lines = open("input.txt").read().splitlines()

lines = [list(line) for line in lines]

def count_adjs(grid, i, j, m, n):
    count = 0
    for l in [i -1, i, i + 1]:
        for k in [j - 1, j, j + 1]:
            if (l == i and j == k) or l < 0 or k < 0 or l >= m or k >= n:
                continue

            if(grid[l][k] == '@'):
                count += 1

    return count

part1 = 0
part2 = 0
m = len(lines)
n = len(lines[0])


for i, line in enumerate(lines):
    for j in range(len(line)):
        if lines[i][j] == '@' and count_adjs(lines, i, j, m, n) < 4:
            part1 += 1

found = True
while found:
    found = False
    for i, line in enumerate(lines):
        for j in range(len(line)):
            if lines[i][j] == '@' and count_adjs(lines, i, j, m, n) < 4:
                lines[i][j] = '.'
                part2 += 1
                found = True


print(part1)
print(part2)