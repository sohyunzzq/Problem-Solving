n = int(input())
coor = []
for i in range(n):
	coor.append(list(map(int, input().split())))

coor.sort(key = lambda x: (x[1], x[0]))
for item in coor:
	print(item[0], item[1])