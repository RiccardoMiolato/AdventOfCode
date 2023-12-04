import re

file = open("input.txt", "r")
lines = file.readlines()

res = 0

for line in lines:
    line = line.replace('  ', ' ').split(': ')[1]
    numbers = line.split(' | ')

    numbers[0] = '\\b(?:' + numbers[0].replace(' ', '|') + ')\\b'

    print(numbers[0])
    print(numbers[1])

    length = len(re.findall(numbers[0], numbers[1]))
    
    if length != 0:
        res += pow(2, length - 1)
        print(str(re.findall(numbers[0], numbers[1]) )+ "   " + str(pow(2, length - 1)))

print(res)