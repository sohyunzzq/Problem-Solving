def check():
	for item in finger:
		if item not in fox:
			return False
	
	for item in fox:
		if item not in finger:
			return False

	return True

n = int(input())

fox = [[1, 3], [1, 4], [3, 4]]

finger = []
for i in range(n):
	tmp = list(map(int, input().split()))
	tmp.sort()

	finger.append(tmp)

if check():
	print("Wa-pa-pa-pa-pa-pa-pow!")
else:
	print("Woof-meow-tweet-squeek")