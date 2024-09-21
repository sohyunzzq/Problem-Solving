t = int(input())
for _ in range(t):
	case = int(input())
	
	num = [0] * 101
	lst = list(map(int, input().split()))

	for number in lst:
		num[number] += 1

	maxi = max(num)
	
	for i in range(100, -1, -1):
		if num[i] == maxi:
			print("#{} {}".format(case, i))
			break