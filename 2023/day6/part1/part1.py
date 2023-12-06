import re

file = open("input.txt", "r")
lines = file.readlines()

times = [int(x) for x in re.findall("\d+", lines[0])]
distances = [int(x) for x in re.findall("\d+", lines[1])]
res = 1

for i in range(len(times)):
    count = 0

    for x in range(times[i]):
        tmp = x * (times[i] - x)

        if tmp > distances[i]:
            count += 1
    
    res *= count

print(res)