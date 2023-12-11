file = open("input.txt", "r")
lines = file.readlines()

points = []
expansion = 1000000

def parseInput():
    for i, line in enumerate(lines):
        lines[i] = [x for x in line.replace('\n', '')]

    addlineat = []
    count = 0
    found = False

    for i, line in enumerate(lines):
        found = False

        for j, char in enumerate(line):
            if char == '#':
                count += 1
                found = True

        if not found:
            addlineat.append(i)

    for n in addlineat[::-1]:
        for i in range(len(lines[n])):
            lines[n][i] = expansion

    addlineat = []
    length = len(lines[0])

    for j in range(length):
        found = False
        for i in range(len(lines)):
            if lines[i][j] == '#':
                found = True

        if not found:
            addlineat.append(j)

    for n in addlineat[::-1]:
        for i in range(len(lines)):
            lines[i][n] = expansion

    for i in range(len(lines)):
        for j in range(len(lines[0])):
            if lines[i][j] == '#':
                points.append((i, j))

def cleanMatrix():
    visited = []

    for i, line in enumerate(lines):
        visited.append([])
        for j, char in enumerate(line):
            visited[i].append(-1)


    return visited

def bfs(row, col):
    sum = 0
    queue = [(row, col, 0)]
    visited  = cleanMatrix()

    while not len(queue) == 0:
        pos = queue.pop(0)

        if visited[pos[0]][pos[1]] == -1:
            if lines[pos[0]][pos[1]] == '#':
                sum += pos[2]

            visited[pos[0]][pos[1]] = (pos[2], lines[pos[0]][pos[1]])

            for newPos in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                if pos[0] + newPos[0] >= 0 and pos[0] + newPos[0] < len(visited):
                    if pos[1] + newPos[1] >= 0 and pos[1] + newPos[1] < len(visited[0]):
                        if lines[pos[0] + newPos[0]][pos[1] + newPos[1]] in ['.', '#']:
                            queue.append((pos[0] + newPos[0], pos[1] + newPos[1], pos[2] + 1))
                        else:
                            queue.append((pos[0] + newPos[0], pos[1] + newPos[1], pos[2] + expansion))

    return sum


parseInput()

res = 0
for point in points:
    res += bfs(point[0], point[1])
    lines[point[0]][point[1]] = '.'

print(res)