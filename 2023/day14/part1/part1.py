file = open("input.txt", "r")
lines = file.readlines()

def calculateLoad(start, rocks):
    tot = 0
    dim = len(lines)

    for i in range(0, rocks):
        tot += dim - start - i

    return tot

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
