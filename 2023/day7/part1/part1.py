import re

file = open("input.txt", "r")
lines = file.readlines()

sort = {
    '2': 0, 
    '3': 1, 
    '4': 2, 
    '5': 3, 
    '6': 4, 
    '7': 5, 
    '8': 6, 
    '9': 7, 
    'T': 8, 
    'J': 9, 
    'Q': 10, 
    'K': 11, 
    'A': 12 
}

games = []

def category(string):
    matches = re.findall(r"((\d|J|Q|K|A|T)\2+)", string)

    if len(matches) == 0:
        return 0
    elif len(matches) == 1:
        if len(matches[0][0]) == 5:
            return 6
        elif len(matches[0][0]) == 4:
            return 5
        elif len(matches[0][0]) == 3:
            return 3
        elif len(matches[0][0]) == 2:
            return 1
    else:
        if len(matches[0][0]) == 2:
            if len(matches[1][0]) == 3:
                return 4
            else:
                return 2
        else:
            return 4


for line in lines:
    hand = [x for x in line.split()[0]]
    bid = int(line.split()[1])

    sortedHand = hand.copy()
    sortedHand.sort()
    sortedString = ""

    for x in sortedHand:
        sortedString += x
    
    cat = category(sortedString)

    games.append((hand, bid, cat))

games.sort(key=lambda game: (game[2], [sort[x] for x in game[0]]))

res = 0
for i, game in enumerate(games):
    res += (i + 1) * game[1]

print(res)
