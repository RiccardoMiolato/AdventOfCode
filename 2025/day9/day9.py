import shapely

file = open("input.txt").read().splitlines()

points = [(int(line.split(",")[0]), int(line.split(",")[1])) for line in file]

polygon = shapely.Polygon(points)

part1 = 0
part2 = 0
for i in range(len(points)):
    for j in range(i + 1, len(points)):
        area = (abs(points[i][0] - points[j][0]) + 1) * (abs(points[i][1] - points[j][1]) + 1)
        if area > part1:
            part1 = area

        if area > part2:
            vertices = [points[i], (points[i][0], points[j][1]), points[j], (points[j][0], points[i][1])]
            rect = shapely.Polygon(vertices)
            if polygon.contains(rect):
                part2 = area
print(part1)
print(part2)