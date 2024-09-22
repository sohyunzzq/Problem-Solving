for case in range(1, 11):
	dump = int(input())
	lst = list(map(int, input().split()))

	for i in range(dump):
		lst[lst.index(max(lst))] -= 1
		lst[lst.index(min(lst))] += 1

	print("#{} {}".format(case, max(lst) - min(lst)))