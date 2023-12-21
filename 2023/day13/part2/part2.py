file = open("input.txt", "r")
blocks = file.read().split("\n\n")

def testVertical(block, j):
    count = 0
    for k in range(0, j):
        if j - 1 - k >= 0 and j + k < len(block[0]):
            for i in range(0, len(block)):
                if block[i][j - 1 - k] != block[i][j + k]:
                    count += 1

    if count == 1:
        return True
    else:
        return False

def testHorizontal(block, i):
    count = 0
    for k in range(0, i):
        if i - 1 - k >= 0 and i + k < len(block):
            for j in range(0, len(block[0])):
                if block[i - 1 - k][j] != block[i + k][j]:
                    count += 1

    if count == 1:
        return True
    else:
        return False

def Vertical(block):
    for j in range(1, len(block[0])):
        count = 0
        for i in range(len(block)):
            if block[i][j - 1] != block[i][j]:
                count += 1

        if count < 2:
            if testVertical(block, j):
                return j

    return 0

def Horizontal(block):
    for i in range(1, len(block)):
        count = 0
        for j in range(len(block[0])):
            if block[i - 1][j] != block[i][j]:
                count += 1

        if count < 2:
            if testHorizontal(block, i):
                return 100 * i
            
    return 0

res = 0
for block in blocks:
    lines = block.split('\n')

    res += Vertical(lines)
    res += Horizontal(lines)
    
print(res)