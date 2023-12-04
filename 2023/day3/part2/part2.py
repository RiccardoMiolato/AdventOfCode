file = open('input.txt', 'r')
lines = file.readlines()

def getNumber(i, j):
    start = j
    number = 0

    while(lines[i][start - 1].isdigit()):
        start -= 1

    while(lines[i][start].isdigit()):
        number = number * 10 + int(lines[i][start])
        start += 1

    return number

n1 = 0
n2 = 0
sum = 0
for i in range(len(lines)):
    for j in range(len(lines[i])):

        if lines[i][j] == '*':
            if i - 1 >= 0:
                if j - 1 >= 0 and j + 1 < len(lines[i]):
                    if lines[i - 1][j - 1].isdigit() and not lines[i - 1][j].isdigit():
                        if n1 == 0:
                            n1 = getNumber(i - 1, j - 1)
                    elif lines[i - 1][j].isdigit():
                        if n1 == 0:
                            n1 = getNumber(i - 1, j)
                    if lines[i - 1][j + 1].isdigit() and not lines[i - 1][j].isdigit():
                        if n1 == 0:
                            n1 = getNumber(i - 1, j + 1)
                        else:
                            n2 = getNumber(i - 1, j + 1)

            if j - 1 >= 0 and j + 1 < len(lines[i]):
                if lines[i][j - 1].isdigit():
                    if n1 == 0:
                        n1 = getNumber(i, j - 1)
                    else:
                        n2 = getNumber(i, j - 1)
                if lines[i][j + 1].isdigit():
                    if n1 == 0:
                        n1 = getNumber(i, j + 1)
                    else:
                        n2 = getNumber(i, j + 1)
            
            if i + 1 < len(lines):
                if j - 1 >= 0 and j + 1 < len(lines[i]):
                    if lines[i + 1][j - 1].isdigit() and not lines[i + 1][j].isdigit():
                        if n1 == 0:
                            n1 = getNumber(i + 1, j - 1)
                        else:
                            n2 = getNumber(i + 1, j - 1)
                    elif lines[i + 1][j].isdigit():
                        if n1 == 0:
                            n1 = getNumber(i + 1, j)
                        else:
                            n2 = getNumber(i + 1, j)
                    if lines[i + 1][j + 1].isdigit() and not lines[i + 1][j].isdigit():
                        if n1 == 0:
                            n1 = getNumber(i + 1, j + 1)
                        else:
                            n2 = getNumber(i + 1, j + 1)

        if n1 != 0 and n2 != 0:
            print("N1 = " + str(n1))
            print("N2 = " + str(n2))
        
        sum += n1 * n2
        n1 = 0
        n2 = 0
                        
print(sum)
