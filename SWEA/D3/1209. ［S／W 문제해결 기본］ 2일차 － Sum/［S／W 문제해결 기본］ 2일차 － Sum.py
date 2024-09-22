def horizon():
	maxi = 0
	for row in lst:
		maxi = max(maxi, sum(row))
	
	return maxi

def vertical():
	maxi = 0
	
	for col in range(100):
		tmp = []
		for row in range(100):
			tmp.append(lst[row][col])
		maxi = max(maxi, sum(tmp))

	return maxi

def cross():
	rightdown = 0
	for i in range(100):
		rightdown += lst[i][i]

	leftdown = 0
	for i in range(100):
		leftdown += lst[99-i][i]

	return max(rightdown, leftdown)

for case in range(1, 11):
	n = int(input())
	lst = []
	for i in range(100):
		lst.append(list(map(int, input().split())))
	
	ans = max(horizon(), vertical(), cross())

	print("#{} {}".format(case, ans))