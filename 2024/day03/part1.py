import re

file = open("input.txt")
lines = file.readlines()

result = 0

for line in lines:
    operations = re.findall(r"(mul\(\d+,\d+\))", line)

    for operation in operations:
        numbers = [int(el) for el in re.findall(r'\d+', operation)]
        result += numbers[0] * numbers[1]

print(result)