t = int(input())
for case in range(1, t + 1):
	lst = list(map(int, input().split()))

	lst.sort()
	lst.pop(0)
	lst.pop()

	ans = sum(lst) // 8
	if (sum(lst) / 8 * 10) % 10 >= 5:
		ans += 1

	print("#{} {}".format(case, ans))