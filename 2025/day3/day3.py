file = open("input.txt")

map = {}

def largestNum(numbers):
    dp = [[0 for _ in range(len(numbers))] for _ in range(12)]

    dp[0][0] = numbers[0]

    for j in range(12):
        for i in range(j, len(numbers)):
            if j == 0:
                if i > 0:
                    dp[j][i] = max(dp[j][i - 1], numbers[i])
            else:
                dp[j][i] = max(dp[j][i - 1], dp[j - 1][i - 1] * 10 + numbers[i])

    return dp


part1 = 0
part2 = 0

for line in file.readlines():
    line = line.strip()

    numbers = [int(c) for c in line]

    table = largestNum(numbers)

    part1 += table[1][len(numbers) - 1]
    part2 += table[11][len(numbers) - 1]


print(part1)
print(part2)

