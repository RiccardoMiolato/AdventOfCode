file = open("input.txt")

position = 50
mod = 100
part1 = 0
part2 = 0

for line in file.readlines():
    dir = line[0]
    times = int(line[1:])

    while(times > 0):
        if(dir == "R"):
            position += 1
            position = position % mod
            if(position == 0):
                part2 += 1
        else:
            position -= 1
            position = position % mod
            if(position == 0):
                part2 += 1

        times -= 1

    if(position == 0):
        part1 += 1

print(f"Part1: {part1}")
print(f"Part2: {part2}")