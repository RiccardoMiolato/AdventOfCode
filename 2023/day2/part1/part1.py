red = 12
green = 13
blue = 14

textFile = open("input", "r")
lines = textFile.readlines()

somma = 0
count = 1
for line in lines:
    right = True
    plays = line.split(':')[1].replace(';', ',').split(',')

    for play in plays:
        game = play.split()

        if game[1].__eq__('red'):
            if(int(game[0]) > red):
                right = False
                break
        elif game[1].__eq__('green'):
            if(int(game[0]) > green):
                right = False
                break
        elif game[1].__eq__('blue'):
            if(int(game[0]) > blue):
                right = False
                break

    if right:
        somma += count

    count += 1


print(somma)