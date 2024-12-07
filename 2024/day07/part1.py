def is_valid(operators, index, cur_val, result):
    if index >= len(operators):
        return cur_val == result

    return is_valid(operators, index + 1, cur_val * operators[index], result) or is_valid(operators, index + 1, cur_val + operators[index], result)

file = open("input.txt")
lines = [line.rstrip('\n') for line in file.readlines()]

for i in range(len(lines)):
    lines[i] = lines[i].split(': ')
    lines[i][0] = int(lines[i][0])
    lines[i][1] = [int(el) for el in lines[i][1].split()]

sum = 0

for equation in lines:
    if is_valid(equation[1], 1, equation[1][0], equation[0]):
        sum += equation[0]

print(sum)