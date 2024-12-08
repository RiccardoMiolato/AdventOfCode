def install_antinode(i, j):
    if i >= 0 and j >= 0 and i < rows and j < cols:
        antinodes_map[i][j] = True
        return True

    return False

def place_antinodes(antennas):
    for antenna in antennas:
        for other in antennas:
            if other != antenna:
                x_diff = antenna[1] - other[1]
                y_diff = antenna[0] - other[0]

                y = antenna[0]
                x = antenna[1]
                while install_antinode(y + y_diff, x + x_diff):
                    y += y_diff
                    x += x_diff


file = open("input.txt")
lines = [line.rstrip("\n") for line in file.readlines()]

map = {}

cols = len(lines[0])
rows = len(lines)

antinodes_map = [[False for _ in range(cols)] for _ in range(rows)]

for i in range(rows):
    for j in range(cols):
        if lines[i][j] != '.':
            antinodes_map[i][j] = True
            if lines[i][j] in map.keys():
                map[lines[i][j]].append((i, j))
            else:
                map[lines[i][j]] = [(i, j)]

for key in map.keys():
    place_antinodes(map[key])

num_antinodes = 0

for i in range(rows):
    for j in range(cols):
        if antinodes_map[i][j]:
            num_antinodes += 1

print(num_antinodes)