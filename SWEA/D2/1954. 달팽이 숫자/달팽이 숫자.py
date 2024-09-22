def in_range(x, y):
	if 0 <= x < n and 0 <= y < n:
		return True
	return False

dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]	

t = int(input())
for case in range(1, t + 1):
	n = int(input())
	
	dr = 0
	x, y = 0, 0

	lst = []
	for i in range(n):
		lst.append([0] * n)

	for i in range(1, n*n+1):
		lst[x][y] = i
		nx, ny = x + dx[dr], y + dy[dr]
		if not in_range(nx, ny) or lst[nx][ny] != 0:
			dr = (dr + 1) % 4
			nx, ny = x + dx[dr], y + dy[dr]

		x, y = nx, ny

	print("#{}".format(case))
	for row in lst:
		for col in row:
			print(col, end = " ")
		print("")