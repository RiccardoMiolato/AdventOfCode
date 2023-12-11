dict = {
    'F': [(+1, 0), (0, +1)],
    '7': [(+1, 0), (0, -1)],
    'L': [(0, +1), (-1, 0)],
    'J': [(0, -1), (-1, 0)],
    '|': [(+1, 0), (-1, 0)],
    '-': [(0, -1), (0, +1)]
}

file = open("input.txt", "r")
lines = file.readlines()

start = None


for i, line in enumerate(lines):
    lines[i] = [x for x in line if x != '\n']
    for j, char in enumerate(line):
        if char == 'S':
            start = (i, j)

            placeHolder = ''

            if i > 0 and i < len(lines) and lines[i - 1][j] in ['|', 'F', '7'] and lines[i + 1][j] in ['|', 'L', 'J']:
                placeHolder = '|'
            elif j > 0 and j < len(lines[i]) and lines[i][j + 1] in ['-', 'J', '7'] and lines[i][j - 1] in ['-', 'F', 'L']:
                placeHolder = '-'
            elif i > 0 and j < len(lines[i]) and not lines[i + 1][j] in ['.', '-', '7', 'F'] and not lines[i][j + 1] in ['.', '|', 'L', 'F']:
                placeHolder = 'F'
            elif i > 0 and j > 0 and not lines[i + 1][j] in ['.', '-', '7','F'] and not lines[i][j - 1] in ['.', '|', 'J', '7']:
                placeHolder = '7'
            elif i < len(lines) and j < len(lines[i]) and not lines[i - 1][j] in ['.', '-', 'J', 'L'] and not lines[i][j + 1] in ['.', '|', 'L', 'F']:
                placeHolder = 'L'
            elif i < len(lines) and j > 0 and not lines[i - 1][j] in ['.', '-', 'J', 'L'] and not lines[i][j - 1] in ['.', '|', 'J', '7']:
                placeHolder = 'J'

            lines[i][j] = placeHolder

queue = [(start, 0)]
res = 0

while not len(queue) == 0:
    tmp = queue.pop(0)

    key = lines[tmp[0][0]][tmp[0][1]]

    if not isinstance(lines[tmp[0][0]][tmp[0][1]], int):
        lines[tmp[0][0]][tmp[0][1]] = tmp[1]
        res = max(res, tmp[1])

        newCoord = dict[key]

        if tmp[1] == 0:
            queue.append(((tmp[0][0] + newCoord[0][0], tmp[0][1] + newCoord[0][1]), tmp[1] + 1, newCoord[0]))
            queue.append(((tmp[0][0] + newCoord[1][0], tmp[0][1] + newCoord[1][1]), tmp[1] + 1, newCoord[1]))
        else:
            if newCoord[0] == (-tmp[2][0], -tmp[2][1]):
                queue.append(((tmp[0][0] + newCoord[1][0], tmp[0][1] + newCoord[1][1]), tmp[1] + 1, newCoord[1]))
            else:
                queue.append(((tmp[0][0] + newCoord[0][0], tmp[0][1] + newCoord[0][1]), tmp[1] + 1, newCoord[0]))

print(res)
