file = open("input.txt", "r")
lines = file.readlines()

power = []

row = 0
col = 0

def moveDown(i, j):
    while i < row:
        power[i][j] = True
        
        if i + 1 < row:
            if lines[i + 1][j] == '-':
                if not power[i + 1][j]:
                    moveRight(i + 1, j)
                    moveLeft(i + 1, j)
                break
            elif lines[i + 1][j] == '\\':
                moveRight(i + 1, j)
                break
            elif lines[i + 1][j] == '/':
                moveLeft(i + 1, j)
                break
        
        i += 1


def moveUp(i, j):
    while i >= 0:
        power[i][j] = True
        
        if i - 1 >= 0:
            if lines[i - 1][j] == '-':
                if not power[i - 1][j]:
                    moveRight(i - 1, j)
                    moveLeft(i - 1, j)
                break
            elif lines[i - 1][j] == '\\':
                moveLeft(i - 1, j)
                break
            elif lines[i - 1][j] == '/':
                moveRight(i - 1, j)
                break

        i -= 1

def moveRight(i, j):
    while j < col:
        power[i][j] = True

        if j + 1 < col:
            if lines[i][j + 1] == '|':
                if not power[i][j + 1]:
                    moveUp(i, j + 1)
                    moveDown(i, j + 1)
                break
            elif lines[i][j + 1] == '\\':
                moveDown(i, j + 1)
                break
            elif lines[i][j + 1] == '/':
                moveUp(i, j + 1)
                break
        
        j += 1
        
def moveLeft(i, j):
    while j >= 0:
        power[i][j] = True

        if j - 1 >= 0:    
            if lines[i][j - 1] == '|':
                if not power[i][j - 1]:
                    moveUp(i, j - 1)
                    moveDown(i, j - 1)
                break
            elif lines[i][j - 1] == '\\':
                moveUp(i, j - 1)
                break
            elif lines[i][j - 1] == '/':
                moveDown(i, j - 1)
                break
        
        j -= 1

for i in range(len(lines)):
    lines[i] = [x for x in lines[i].replace('\n', '')]

row = len(lines)
col = len(lines[0])

for i in range(0, row):
    power.append([])
    for j in range(0, col):
        power[i].append(False)

if lines[0][0] in ['|', '\\']:
    moveDown(0, 0)
elif lines[0][0] == '/':
    moveUp(0, 0)
else:
    moveRight(0, 0)

count = 0
for line in power:
    for el in line:
        if el:
            count += 1

print(count)