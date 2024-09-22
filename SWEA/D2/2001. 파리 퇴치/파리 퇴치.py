def catch():
	maxi = 0
	for row in range(n-m+1):
		for col in range(n-m+1):
			sum = 0
			#lst[row][col]이 왼쪽 위
			for i in range(m):
				for j in range(m):
					sum += lst[row+i][col+j]
			maxi = max(sum, maxi)
	return maxi

t = int(input())
for case in range(1, t + 1):
	n, m = map(int, input().split())
	lst = []
	for i in range(n):
		lst.append(list(map(int, input().split())))

	print("#{} {}".format(case, catch()))