textFile = open("input", "r")
lines = textFile.readlines()

somma = 0
for line in lines:
    red = 0
    blue = 0
    green = 0

    right = True
    plays = line.split(':')[1].replace(';', ',').split(',')

    for play in plays:
        game = play.split()

        if game[1].__eq__('red'):
            if(int(game[0]) > red):
                red = int(game[0])
        elif game[1].__eq__('green'):
            if(int(game[0]) > green):
                green = int(game[0])
        elif game[1].__eq__('blue'):
            if(int(game[0]) > blue):
                blue = int(game[0])

    somma += red * green * blue

print(somma)