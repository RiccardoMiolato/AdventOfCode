import re

file = open("input.txt", "r")
lines = file.readlines()

graph = {}

for i, line in enumerate(lines):
    if i == 0:
        steps = [x for x in line.replace('\n', '')]

    if i > 1:
        nodes = re.findall("[A-Z]+", line)

        graph[nodes[0]] = (nodes[1], nodes[2])

node = "AAA"
count = 0
while not node == "ZZZ":
    instruction = steps.pop(0)
    count += 1

    if instruction == 'L':
        node = graph[node][0]
    else:
        node = graph[node][1]

    steps.append(instruction)

print(count)