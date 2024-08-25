t = int(input())
for i in range(t):
	a, b = map(int, input().split())
	sum1 = 0

	if a == 1:
		sum1 += 5000000
	elif 2 <= a <= 3:
		sum1 += 3000000
	elif 4 <= a <= 6:
		sum1 += 2000000
	elif 7 <= a <= 10:
		sum1 += 500000
	elif 11 <= a <= 15:
		sum1 += 300000
	elif 16 <= a <= 21:
		sum1 += 100000

	if b == 1:
		sum1 += 5120000
	elif 2 <= b <= 3:
		sum1 += 2560000
	elif 4 <= b <= 7:
		sum1 += 1280000
	elif 8 <= b <= 15:
		sum1 += 640000
	elif 16 <= b <= 31:
		sum1 += 320000

	print(sum1)