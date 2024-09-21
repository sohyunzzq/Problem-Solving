def check():
	for i in range(n):
		if lst[a-1][i] > lst[a-1][b-1]:
			return True
	
	for i in range(n):
		if lst[i][b-1] > lst[a-1][b-1]:
			return True

	return False

n, a, b = map(int, input().split())

lst = []
for i in range(n):
	lst.append(list(map(int, input().split())))

if check():
	print("ANGRY")
else:
	print("HAPPY")