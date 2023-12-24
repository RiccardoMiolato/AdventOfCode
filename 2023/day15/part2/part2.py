file = open("input.txt", "r")
lines = file.readlines()

boxes = {}

for i in range(0, 256):
    boxes[i] = []

for line in lines:
    parts = line.split(',')

    res = 0

    for part in parts:
        hashValue = 0
        for i, char in enumerate(part):
            if not char in ['=', '-']:
                hashValue += ord(char)
                hashValue *= 17
                hashValue %= 256
            else:
                break

        if '=' in part:
            found = False

            for j, elem in enumerate(boxes[hashValue]):
                if elem.split()[0] == part.split('=')[0]:
                    boxes[hashValue][j] = part.replace('=', ' ')
                    found = True
                    break

            if not found:
                boxes[hashValue].append(part.replace('=', ' '))
            
        elif '-' in part:
            delete = []
            for j, elem in enumerate(boxes[hashValue]):
                if elem.split()[0] == part.replace('-', ''):
                    boxes[hashValue].pop(j)
                    break

for box in boxes:    
    for i, el in enumerate(boxes[box]):
        res += (box + 1) * (i + 1) * int(boxes[box][i].split()[1])

print(res)
