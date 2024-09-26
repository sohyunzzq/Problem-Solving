n = int(input())
print("Gnomes:")
for i in range(n):
	lst = list(map(int, input().split()))

	if sorted(lst) == lst or sorted(lst, reverse = True) == lst:
		print("Ordered")
	else:
		print("Unordered")