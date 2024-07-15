while True:
	num = int(input())
	if num == 0:
		break
	total = 0
	for i in range(1, num+1):
		total += i
	print(total)