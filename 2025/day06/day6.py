filename = "input.txt"

file = open(filename)
lines = [line.split() for line in file.read().splitlines()]
operations = lines[len(lines) - 1]

part1 = 0
part2 = 0

for i in range(len(lines[0])):
    n = len(lines)
    op = operations[i]
    if op == '+':
        curr_op = 0
    else:
        curr_op = 1

    for j in range(n - 1):
        if op == '+':
            curr_op += int(lines[j][i])
        else:
            curr_op *= int(lines[j][i])

    part1 += curr_op

lines = [line for line in open(filename).read().splitlines()]

n = len(lines)
last_op = lines[n - 1][0]
index = 0
operations = []
for i in range(1, len(lines[n - 1])):
    if lines[n - 1][i] != ' ':
        operations.append((last_op, i - index))
        last_op = lines[n - 1][i]
        index = i

operations.append((last_op, 3))

i = 0
for (op, offset) in operations:
    if op == '+':
        curr_op = 0
    else:
        curr_op = 1

    for j in range(offset - 1):
        number = 0
        for k in range(len(lines) - 1):
            if i + j >= len(lines[k]):
                continue

            if lines[k][i + j] != ' ':
                number = number * 10 + int(lines[k][i + j])

        if op == '+':
            curr_op += number
        else:
            curr_op *= number

    part2 += curr_op

    i += offset


print(part1)
print(part2)