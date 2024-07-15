lst = [1, 1, 2, 2, 2, 8]

lst2 = list(map(int, input().split()))

for i in range(6):
	print(lst[i] - lst2[i], end = " ")