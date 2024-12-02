def check_line(line):
    decreasing = False

    if line[0] > line[1]:
        decreasing = True

    for i in range(0, len(line) - 1):
        if decreasing:
            if line[i] <= line[i + 1]:
                return False
            elif line[i] - line[i + 1] > 3:
                return False
        else:
            if line[i] >= line[i + 1]:
                return False
            elif line[i + 1] - line[i] > 3:
                return False

    return True

file = open("input.txt")
lines = [line.split() for line in file.readlines()]
safe_lines = 0

for line in lines:
    line = [int(el) for el in line]
    found = False

    for i in range(0, len(line)):
        custom_line = line[0:i] + line[i + 1::]
        if check_line(custom_line):
            found = True

    if found:
        safe_lines += 1

print(safe_lines)
