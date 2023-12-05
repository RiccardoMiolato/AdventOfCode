import re

file = open("input.txt", "r")
lines = file.readlines()

seeds = []
translationIntervals = []

def intersect(a: (int, int), b: (int, int)):
    if a[0] >= b[0] and a[0] <= b[1]:
        if a[1] >= b[1]:
            return (a[0], b[1])
        else:
            return (a[0], a[1])
    elif b[0] >= a[0] and b[0] <= a[1]:
        if b[1] <= a[1]:
            return (b[0], b[1])
        else:
            return (b[0], a[1])
    elif a[1] >= b[0] and a[1] <= b[1]:
        if a[0] >= b[0]:
            return (a[0], a[1])
        else:
            return (b[0], a[1])
    elif b[1] >= a[0] and b[1] <= a[1]:
        if b[0] >= a[0]:
            return (b[0], b[1])
        else:
            return (a[0], b[1])
    
    return None
        

for i, line in enumerate(lines):
    if i == 0:
        seeds = [int(x) for x in re.findall("\d+", line)]

        intervals = []

        for j in range(len(seeds)):
            if j % 2 == 1:
                intervals.append((seeds[j - 1], seeds[j - 1] + seeds[j]))

        print(intervals)
    else:
        if re.search("\d+ \d+ \d+", line):
            numbers = [int(x) for x in re.findall("\d+", line)]
            translationIntervals.append([(numbers[1], numbers[1] + numbers[2]), (numbers[0], numbers[0] + numbers[2])])
        elif re.search("^\s*$", line) and translationIntervals != []:
            queue = intervals
            intervals = []
            count = 20
            print('---------------------------------------------------')
            while len(queue) > 0 and count > 0:
                count -= 1
                added = False
                interval = queue.pop(0)
                print("Analizzo ", interval)
                for translation in translationIntervals:
                    intersection = intersect(interval, translation[0])
                    print("Confronto tra ", interval, translation[0])
                    if intersection:
                        print("Confronto valido, risultato ", intersection)
                        
                        if intersection[0] > interval[0]:
                            print("Aggiungo ", (interval[0], intersection[0] - 1))
                            queue.append((interval[0], intersection[0] - 1))
                        
                        if intersection[1] < interval[1]:
                            print("Aggiungo ", (intersection[1], interval[1]))
                            queue.append((intersection[1] + 1, interval[1]))


                        tmp = list(intersection)
                        tmp[0] = translation[1][0] + intersection[0] - translation[0][0]
                        tmp[1] = translation[1][1] + intersection[1] - translation[0][1]
                        intersection = tuple(tmp)

                        added = True
                        intervals.append(intersection)

                        print("Intersezione traslata aggiunta a intervals: ", intersection)
                
                if not added:
                    print("Intersezione non esistente, aggiungo ", interval)
                    intervals.append(interval)

            print(intervals)    
            translationIntervals = []

list = [x[0] for x in intervals]
print(min(list))