import re

file = open("input.txt", "r")
lines = file.readlines()

res = 0

dict = {1: 0}

def elaboratLine(i, line):
    line = line.replace('  ', ' ').split(': ')[1]
    numbers = line.split(' | ')

    numbers[0] = '\\b(?:' + numbers[0].replace(' ', '|') + ')\\b'

    length = len(re.findall(numbers[0], numbers[1]))
    
    if length != 0:
        for j in range(length):
            if i + j + 2 in dict.keys():
                print(i + j + 2)
                print(j + 1)
                print(dict[i + j + 2])
                print(dict[j + 1])
                print('----')
                dict[i + j + 2] = dict[i + j + 2] +  dict[i + 1]
            else:
                dict[i + j + 2] = dict[i + 1]

    print(dict)

for i, line in enumerate(lines):
    if not i + 1 in dict.keys():
        dict[i + 1] = 1
    else:
        dict[i + 1] += 1
            
    elaboratLine(i, line)

for k in dict.keys():
    res += dict[k]

print(res)