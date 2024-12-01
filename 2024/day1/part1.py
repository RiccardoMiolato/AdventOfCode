right_list = []
left_list = []

sum = 0

# Read data from file
file = open("input.txt")

for line in file.readlines():
    line = line.split()
    left_list.append(int(line[0]))
    right_list.append(int(line[1]))

# Sort both lists
right_list.sort()
left_list.sort()

for i in range(0, len(right_list)):
    sum += abs(right_list[i] - left_list[i])

print(sum)