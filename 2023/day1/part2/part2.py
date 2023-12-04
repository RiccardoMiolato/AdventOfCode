def identify_digit(line:str, i:int):
    if line[i].isdigit(): return int(line[i])
    elif line[i:i+3] == "one": return 1
    elif line[i:i+3] == "two": return 2
    elif line[i:i+5] == "three": return 3
    elif line[i:i+4] == "four": return 4
    elif line[i:i+4] == "five": return 5
    elif line[i:i+3] == "six": return 6
    elif line[i:i+5] == "seven": return 7
    elif line[i:i+5] == "eight": return 8
    elif line[i:i+4] == "nine": return 9

    return None


textFile = open("input.txt", "r")

lines = textFile.readlines()

somma = 0

for line in lines:
    digits = []

    for i in range(len(line)):
        c = identify_digit(line, i)
        if c:
            digits.append(c)

    somma += int(str(digits[0]) + str(digits[-1]))

print(somma)