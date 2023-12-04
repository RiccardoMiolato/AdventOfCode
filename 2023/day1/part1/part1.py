def first(s):
    for c in s:
        if c.isnumeric():
            return int(c)

def last(s):
    return first(s[::-1])

textFile = open("input.txt", "r")

lines = textFile.readlines()

somma = 0
for line in lines:
    somma += first(line) * 10 + last(line)

print(somma)