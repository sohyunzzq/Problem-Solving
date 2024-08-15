n = int(input())
for i in range(1, n+1):
	lst = list(map(int, input().split()))
	print("Case #{}: {}".format(i, max(lst)))