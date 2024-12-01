file = open("input.txt", "r")
lines = file.read().split('\n')

for i in range(len(lines)):
    lines[i] = [x for x in lines[i]]

def calculateLoad(start, rocks):
    tot = 0
    dim = len(lines)

    for i in range(0, rocks):
        tot += dim - start - i

    return tot

def moveNorth():
    for j in range(len(lines[0])):
        for i in range(len(lines)):
            if lines[i][j] == 'O':
                line = i

                while line > 0:
                    if lines[line - 1][j] == '.':
                        lines[line][j] = '.'
                        lines[line - 1][j] = 'O'
                    else:
                        break

                    line -= 1
                
def moveWest():
    for i in range(len(lines)):
        for j in range(len(lines[0])):
            if lines[i][j] == 'O':
                col = j

                while col > 0:
                    if lines[i][col - 1] == '.':
                        lines[i][col - 1] = 'O'
                        lines[i][col] = '.'
                    else:
                        break

                    col -= 1

def moveSouth():
    for j in range(len(lines[0])):
        for i in range(len(lines)):
            row = len(lines) - 1 - i
            if lines[row][j] == 'O':
                line = row

                while line < len(lines) - 1:
                    if lines[line + 1][j] == '.':
                        lines[line][j] = '.'
                        lines[line + 1][j] = 'O'
                    else:
                        break

                    line += 1
                
def moveEast():
    for i in range(len(lines)):
        for j in range(len(lines[0])):
            column = len(lines[0]) - 1 - j
            if lines[i][column] == 'O':
                col = column

                while col < len(lines[0]) - 1:
                    if lines[i][col + 1] == '.':
                        lines[i][col + 1] = 'O'
                        lines[i][col] = '.'
                    else:
                        break

                    col += 1

def cycle():
    moveNorth()
    moveWest()
    moveSouth()
    moveEast()

for k in range(0, 1000000000):
    print(k/10000000, '%')
    cycle()

for line in lines:
    print(line)

res = 0
for j in range(len(lines[0])):
    lastRock = -1
    nRocks = 0
    for i in range(len(lines)):
        if lines[i][j] == 'O':
            nRocks += 1
        elif lines[i][j] == '#':
            if nRocks > 0:
                res += calculateLoad(lastRock + 1, nRocks)

            lastRock = i
            nRocks = 0

    if nRocks > 0:
        res += calculateLoad(lastRock + 1, nRocks)

print(res)
