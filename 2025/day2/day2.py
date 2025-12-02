file = open("input.txt").read()

ranges = file[:-1].split(",")
part1 = 0
part2 = 0

for _range in ranges:
    bounds = _range.split("-")

    for i in range(int(bounds[0]), int(bounds[1]) + 1):
        string = str(i)

        for j in range(0, len(string) // 2 + 1):
            if(j > 0):
                if(len(string) % j == 0):
                    count = string.count(string[0:j])
                    if(count > 1 and len(string[0:j]) * count == len(string)):
                        part2 += i
                        break
            else:
                count = string.count(string[0:j])
                if(count > 1 and len(string) % count == 0):
                    part2 += i
                    break

        if(string[0:len(str(string))//2] == string[len(str(string))//2:]):
           part1 += i

print(part1)
print(part2)