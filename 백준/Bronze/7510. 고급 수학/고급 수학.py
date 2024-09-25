n = int(input())
for i in range(1, n+1):
	lst = list(map(int, input().split()))
	lst.sort()

	print("Scenario #{}:".format(i))
	if lst[2] ** 2 == lst[0] ** 2 + lst[1] ** 2:
		print("yes")
	else:
		print("no")

	print()