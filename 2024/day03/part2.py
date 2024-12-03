import re

file = open("input.txt")
lines = file.readlines()

result = 0
do_operation = True

for line in lines:
    operations = re.findall(r"mul\(\d+,\d+\)|don't\(\)|do\(\)", line)

    for operation in operations:
        if operation == "do()":
            do_operation = True
        elif operation == "don't()":
            do_operation = False
        elif do_operation:
            numbers = [int(el) for el in re.findall(r'\d+', operation)]
            result += numbers[0] * numbers[1]

print(result)