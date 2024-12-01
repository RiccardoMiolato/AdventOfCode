place_list = []
repetitions = {}

sum = 0

# Read data from file
file = open("input.txt")

for line in file.readlines():
    line = line.split()
    place_list.append(int(line[0]))

    key = int(line[1])
    if repetitions.get(key) != None:
        repetitions[key] += 1
    else:
        repetitions[key] = 1

for place in place_list:
    if repetitions.get(place):
        sum += repetitions[place] * place

print(sum)