n, k = map(int, input().split())

lst = []
for i in range(n + 1):
	lst.append([0] * (n + 1))

for row in range(n+1):
	for col in range(n+1):
		if row == col or col == 0:
			lst[row][col] = 1

		elif row > col:
			lst[row][col] = lst[row-1][col-1] + lst[row-1][col]

print(lst[n][k])