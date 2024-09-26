n = int(input())

coor = []
for i in range(n):
	coor.append(list(map(int, input().split())))

coor.sort(key = lambda x: (x[0], x[1]))

for i in range(n):
	print(coor[i][0], coor[i][1])