import re

file = open("input.txt", "r")
lines = file.readlines()

sort = {
    '2': 1, 
    '3': 2, 
    '4': 3, 
    '5': 4, 
    '6': 5, 
    '7': 6, 
    '8': 7, 
    '9': 8, 
    'T': 9, 
    'J': 0, 
    'Q': 10, 
    'K': 11, 
    'A': 12 
}

games = []
        
def category(string):
    joker = False
    matches = re.findall(r"((\d|J|Q|K|A|T)\2+)", string)

    if re.search('J', string):
        joker = True

    if len(matches) == 0:
        if not joker:
            return 0
        else:
            return 1
    elif len(matches) == 1:
        if len(matches[0][0]) == 5:
            return 6
        elif len(matches[0][0]) == 4:
            if not joker:
                return 5
            else:
                return 6
        elif len(matches[0][0]) == 3:
            if not joker:
                return 3
            else:
                return 5
        elif len(matches[0][0]) == 2:
            if not joker:
                return 1
            else:
                return 3
    else:
        if len(matches[0][0]) == 2:
            if len(matches[1][0]) == 3:
                if not joker:
                    return 4
                else: 
                    return 6
            else:
                if not joker:
                    return 2
                else:
                    if matches[0][0] == 'JJ' or matches[1][0] == 'JJ':
                        return 5
                    else:
                        return 4
        else:
            if not joker:
                return 4
            else: 
                return 6


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
