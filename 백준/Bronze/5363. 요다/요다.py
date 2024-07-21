n = int(input())

for i in range(n):
	lst = list(input().split())
	for j in range(2, len(lst)):
		print(lst[j], end = " ")
	print(lst[0], lst[1])