t = int(input())
for case in range(t):
	n = int(input())
	lst = list(map(int, input().split()))

	maxi = 0
	price = 0
	for i in range(n-1, -1, -1):
		if lst[i] > maxi:
			maxi = lst[i]
		else:
			price += maxi - lst[i]

	print("#{} {}".format(case+1, price))