file = open("input.txt", "r")
lines = file.readlines()

for line in lines:
    parts = line.split(',')

    res = 0

    for part in parts:
        hashValue = 0
        for i, char in enumerate(part):
            hashValue += ord(char)
            hashValue *= 17
            hashValue %= 256

        res += hashValue

print(res)
