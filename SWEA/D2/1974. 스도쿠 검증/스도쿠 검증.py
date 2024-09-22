def check(num):
	for i in range(9):
		if num[i] > 1:
			return False
	return True

def sudoku():
	for row in range(9):
		num = [0] * 10
		for col in range(9):
			num[lst[row][col]] += 1
		
		if not check(num):
			return False
	
	for col in range(9):
		num = [0] * 10
		for row in range(9):
			num[lst[row][col]] += 1
		
		if not check(num):
			return False

	for x in range(0, 7, 3):
		for y in range(0, 7, 3):
			num = [0] * 10
			for row in range(3):
				for col in range(3):
					num[lst[x+row][y+col]] += 1
		if not check(num):
			return False
	return True


t = int(input())
for case in range(1, t + 1):
	lst = []
	for i in range(9):
		lst.append(list(map(int, input().split())))

	if sudoku():
		print("#{} 1".format(case))
	else:
		print("#{} 0".format(case))