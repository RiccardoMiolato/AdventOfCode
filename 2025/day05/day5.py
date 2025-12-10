lines = open("input1.txt").read().splitlines()

setup = True
ranges = []

part1 = 0
part2 = 0

for line in lines:
    if line == "":
        setup = False
        continue

    if setup:
        ranges.append([int(el) for el in line.split("-")])
    else:
        value = int(line)
        for _range in ranges:
            if(_range[0] <= value and value <= _range[1]):
                part1 += 1
                break


ranges.sort(key=lambda x: (x[0], x[1]))

last_end = 0
last_start = 0

for r in ranges:
    if(r[0] > last_end):
        if(last_end != 0):
            part2 += last_end - last_start + 1
        last_end = r[1]
        last_start = r[0]
    else:
        last_end = max(last_end, r[1])

part2 += last_end - last_start + 1

print(part1)
print(part2)