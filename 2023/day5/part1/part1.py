import re

file = open("input.txt", "r")
lines = file.readlines()

seeds = []
translated = []
done = []
for i, line in enumerate(lines):
    if i == 0:
        seeds = [int(x) for x in re.findall("\d+", line)]
        print(seeds)

    if re.search("\d+ \d+ \d+", line) and i != 0:
        numbers = [int(x) for x in re.findall("\d+", line)]
        
        for x in seeds:
            if numbers[1] <= x and x < numbers[1] + numbers[2]:
                done.append(x)
                translated.append(numbers[0] + x - numbers[1])

    if re.search("^\s*$", line):
        if translated != []:
            for x in seeds:
                if not x in done:
                    translated.append(x)

            seeds = translated

            done = []
            translated = []

for i in range(len(seeds)):
    if translated != []:
        for x in seeds:
            if not x in done:
                translated.append(x)

        seeds = translated

        done = []
        translated = []

print(min(seeds))
