DP = []

DP.append(0)
DP.append(1)

n = int(input())
for i in range(2, n + 1):
    DP.append(DP[i-1]+DP[i-2])

print(DP[n])