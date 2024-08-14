def ans(num):
	for i in range(1, num):
		sum1 = i
		for j in str(i):
			sum1 += int(j)

		if sum1 == num:
			return i
	return 0

n = int(input())
print(ans(n))