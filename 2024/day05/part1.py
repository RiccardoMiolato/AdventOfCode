file = open("input.txt")
lines = file.readlines()

is_rules = True

rules = {}
updates = []

for line in lines:
    if line == "\n":
        is_rules = False
        continue

    if is_rules:
        pages = [int(el) for el in line.split("|") if el != "\n"]
        if rules.get(pages[1]):
            rules[pages[1]].append(pages[0])
        else:
            rules[pages[1]] = [pages[0]]
    else:
        updates.append([int(el) for el in line.split(',')])

sum = 0

for update in updates:
    right = True
    for (i, value) in enumerate(update):
        if rules.get(value):
            dependencies = rules[value]
            for val in dependencies:
                if val in update[i + 1::]:
                    right = False
                    break

        if not right:
            break
    if right:
        sum += update[int(len(update) / 2)]

print(sum)