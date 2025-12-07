# PART 1
def scroll(map, visited, i, j):
    visited[i][j] = True
    count = 0

    if(i + 1 >= len(map)):
        return 0

    if map[i + 1][j] == "^" and not visited[i + 1][j]:
        visited[i + 1][j] = True
        count += 1
        if j - 1 >= 0 and not visited[i + 1][j - 1]:
            count += scroll(map, visited, i + 1, j - 1)

        if j + 1 < len(map[0]) and not visited[i + 1][j + 1]:
            count += scroll(map, visited, i + 1, j + 1)
    elif not visited[i + 1][j]:
        count = scroll(map, visited, i + 1, j)

    return count

# PART 2
def quantum_scroll(map, visited, i, j):
    count = 0

    if(i + 1 >= len(map)):
        return 1

    if map[i + 1][j] == "^":
        if visited[i + 1][j] == 0:
            if j - 1 >= 0:
                count += quantum_scroll(map, visited, i + 1, j - 1)

            if j + 1 < len(map[0]):
                count += quantum_scroll(map, visited, i + 1, j + 1)

            visited[i + 1][j] = count
        else:
            count = visited[i + 1][j]
    else:
        count = quantum_scroll(map, visited, i + 1, j)

    return count


map = open("input.txt").read().splitlines()
start = (0, 0)

for i in range(len(map[0])):
    if(map[0][i] == "S"):
        start = (0, i)
        break

visited = [[False for _ in range(len(map[0]))] for _ in range(len(map))]
part1 = scroll(map, visited, start[0], start[1])

visited = [[0 for _ in range(len(map[0]))] for _ in range(len(map))]
part2 = quantum_scroll(map, visited, start[0], start[1])

print(part1)
print(part2)