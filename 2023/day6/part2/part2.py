import re

file = open("input.txt", "r")
lines = file.readlines()

time = ""
for x in re.findall("\d+", lines[0]):
    time += x

distance = ""
for x in re.findall("\d+", lines[1]):
    distance += x

times = [int(time)]
distances = [int(distance)]
res = 1

for i in range(len(times)):
    count = 0

    for x in range(times[i]):
        tmp = x * (times[i] - x)

        if tmp > distances[i]:
            count += 1
    
    res *= count

print(res)