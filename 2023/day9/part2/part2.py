file = open("input.txt", "r")
lines = file.readlines()

def prediction(values):
    last = len(values) - 1
    start = 1
    
    zero = False

    while not zero:
        zero = True
        firstValue = values[start - 1]

        for i in range(start, last + 1):
            values[i - 1] = values[i] - values[i - 1]

            if values[i] != 0 and zero:
                zero = False

        values[last] = firstValue
        last -= 1

    last += 1
    predict = values[last]
 
    for i in range(last + 1, len(values)):
        predict = values[i] - predict

    return predict

res = 0
for line in lines:
    values = [int(x) for x in line.split()]
    
    res += prediction(values)

print(res)
