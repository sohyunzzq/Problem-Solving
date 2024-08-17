t = int(input())

apart = []
for i in range(15):
	apart.append([0] * 15)
for i in range(1, 15):
	apart[0][i] = i
for i in range(1, 15):
	for j in range(1, 15):
		for k in range(1, j+1):
			apart[i][j] += apart[i-1][k]

for i in range(t):
	n = int(input())
	k = int(input())
	print(apart[n][k])