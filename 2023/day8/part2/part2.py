import re
import math

file = open("input.txt", "r")
lines = file.readlines()

graph = {}
starts = []
primeNumbers = []

def isPrime(a):
    for i in range(2, math.ceil(a / 2)):
        if a % i == 0:
            return False
        
    return True

for i, line in enumerate(lines):
    if i == 0:
        steps = [x for x in line.replace('\n', '')]

    if i > 1:
        nodes = re.findall("[0-9A-Z]+", line)
        
        if re.search('..A', nodes[0]):
            starts.append(nodes[0])

        graph[nodes[0]] = (nodes[1], nodes[2])


count = 0
end = False
results = []
tmp = steps.copy()

for node in starts:
    steps = tmp.copy()
    count = 0

    while not re.match('..Z', node):
        instruction = steps.pop(0)
        count += 1

        if instruction == 'L':
            node = graph[node][0]
        else:
            node = graph[node][1]

        steps.append(instruction)

    results.append(count)

primeNumbers = [x for x in range(1, math.ceil(max(results) / 2)) if isPrime(x)]

res = 1
for n in primeNumbers:
    divideOne = False

    for x in results:
        if x % n == 0:
            res *= n
            break
    
print(res)