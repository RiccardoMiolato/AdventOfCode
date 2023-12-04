file = open('input.txt', 'r')
lines = file.readlines()

def check(character):
    if(not character.isdigit() and character != '.'):
        return True

    return False

def checkBefore(i: int, j: int):
    if i - 1 >= 0:
        if j - 1 >= 0 and j + 1 < len(lines):
            return check(lines[j - 1][i - 1]) or check(lines[j][i - 1]) or check(lines[j + 1][i - 1])
        elif j == 0:
            return check(lines[j][i - 1]) or check(lines[j + 1][i - 1])
        else:
            return check(lines[j - 1][i - 1]) or check(lines[j][i - 1])

    return False
            
def checkAfter(i: int, j: int):
    if i + 1 < len(lines):
        if j - 1 >= 0 and j + 1 < len(lines):
            return check(lines[j - 1][i + 1]) or check(lines[j][i + 1]) or check(lines[j + 1][i + 1])
        elif j == 0:
            return check(lines[j][i + 1]) or check(lines[j + 1][i + 1])
        else:
            return check(lines[j - 1][i + 1]) or check(lines[j][i + 1])

    return False

def checkTopAndBottom(i: int, j: int):
    if j - 1 >= 0 and j + 1 < len(lines):
        return check(lines[j - 1][i]) or check(lines[j + 1][i])
    elif j == 0:
        return check(lines[j + 1][i])
    else:
        return check(lines[j - 1][i]) 

somma = 0

for i in range(len(lines)):
    number = 0
    isNumber = False
    adj = False

    for j in range(len(lines[i])):
        if lines[i][j].isdigit():
            if not isNumber:
                adj = checkBefore(j, i)
                isNumber = True
            
            if not adj:
                adj = checkTopAndBottom(j, i)

            number = number * 10 + int(lines[i][j])
        elif isNumber and number != 0:
            if not adj:
                adj = checkAfter(j - 1, i)

            if adj:
                somma += number
            
            number = 0
            adj = False
            isNumber = False


print(somma)