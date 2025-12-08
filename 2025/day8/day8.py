file = open("input.txt").read()

NUMBER_OF_JUNCTIONS = 1000

def euclidean_distance(a, b):
    squared_sum = 0
    for i in [0, 1, 2]:
        squared_sum += (a[i] - b[i]) ** 2

    return squared_sum ** 0.5

boxes = [[int(el) for el in coord.split(",")] for coord in file.splitlines()]

distances = []
for i in range(len(boxes)):
    for j in range(i + 1,len(boxes)):
        distances.append((euclidean_distance(boxes[i], boxes[j]), (i, j)))
distances.sort()


clusters = [-1 for _ in range(len(boxes))]
lens = {}
cluster = 0
circuits = 0
connected = 0

part1 = 1
part2 = 0

for i in range(len(distances)):
    _, (a, b) = distances[i]
    if(clusters[a] == -1 and clusters[b] == -1):
        clusters[a] = cluster
        clusters[b] = cluster
        cluster += 1
        circuits += 1
        connected += 2
        lens[clusters[a]] = 2
    elif(clusters[a] != -1 and clusters[b] == -1):
        clusters[b] = clusters[a]
        lens[clusters[a]] += 1
        connected += 1
    elif(clusters[b] != -1 and clusters[a] == -1):
        clusters[a] = clusters[b]
        connected += 1
        lens[clusters[b]] += 1
    elif clusters[a] != clusters[b]:
        circuits -= 1
        old = clusters[b]
        lens[clusters[a]] += lens[old]
        del lens[old]
        for k in range(len(clusters)):
            if clusters[k] == old:
                clusters[k] = clusters[a]

    if(i == NUMBER_OF_JUNCTIONS - 1):
        lens_sorted = sorted(lens.items(), key=lambda kv: -kv[1])[:3]
        for el in lens_sorted:
            part1 *= el[1]

    if(circuits == 1 and connected == len(boxes)):
        part2 = boxes[a][0] * boxes[b][0]
        break

print(part1)
print(part2)