file = open("input.txt", "r")
blocks = file.read().split("\n\n")

def testVertical(block, j):
    for k in range(0, j):
        if j - 1 - k >= 0 and j + k < len(block[0]):
            for i in range(0, len(block)):
                if block[i][j - 1 - k] != block[i][j + k]:
                    return False

    return True

def verticalMirror(block):
    mirror = False
    for j in range(1, len(block[0])):
        mirror = True

        for i in range(0, len(block)):
            if block[i][j - 1] != block[i][j]:
                mirror = False
                break

        if mirror:
            if(testVertical(block, j)):
                return j
            else:
                mirror = False
        
    return 0

def testHorizontal(block, i):
    for k in range(0, i):
        if i - 1 - k >= 0 and i + k < len(block):
            for j in range(0, len(block[0])):
                if block[i - 1 - k][j] != block[i + k][j]:
                    return False;

    return True

def horizontalMirror(block):
    mirror = False
    for i in range(1, len(block)):
        mirror = True

        for j in range(0, len(block[0])):
            if block[i - 1][j] != block[i][j]:
                mirror = False
                break

        if mirror:
            if(testHorizontal(block, i)):
                return i * 100
            else:
                mirror = False
        
    return 0

res = 0
for block in blocks:
    block = block.split('\n')

    res += verticalMirror(block)
    res += horizontalMirror(block)

print(res)