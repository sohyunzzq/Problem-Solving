for case in range(10):
	n = int(input())
	lst = list(map(int, input().split()))

	ans = 0
	for i in range(2, n-2):
		tmp = [lst[i-2], lst[i-1], lst[i+1], lst[i+2]]

		if lst[i-2] >= lst[i] or lst[i-1] >= lst[i] or lst[i+1] >= lst[i] or lst[i+2] >= lst[i]:
			continue
		
		ans += lst[i] - max(tmp)

	print("#{} {}".format(case+1, ans))