import re
file = open("input.txt", "r")
lines = file.readlines()

def bruteforce(springs, indexS, numbers):
    res = 0

    if indexS < len(springs):
        if springs[indexS] == '?':
            springs[indexS] = '.'
            res += bruteforce(springs, indexS + 1, numbers)
            springs[indexS] = '#'
            res += bruteforce(springs, indexS + 1, numbers)
            springs[indexS] = '?'
        else:
            res += bruteforce(springs, indexS + 1, numbers)
    else:
        count = 0
        i = 0

        for char in springs:
            if char == '#':
                count += 1
            else:
                if count != 0:
                    if i == len(numbers):
                        return 0
                    
                    if count != numbers[i]:
                        return 0
                
                    if i < len(numbers):
                        i += 1
                    else:
                        return 0
                    
                    count = 0

        if count != 0:
            if i == len(numbers) - 1 and count != numbers[i]:
                return 0
            else:
                i += 1

        if i == len(numbers):
            res = 1
    
    return res

p1 = 0
for line in lines:
    parts = line.split()

    springs = [x for x in parts[0]]
    numbers = [int(x) for x in re.findall('\d+', parts[1])]

    combinations = bruteforce(springs, 0, numbers)

    p1 += combinations

print(p1)