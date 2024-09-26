l, p = map(int, input().split())
lst = list(map(int, input().split()))

for item in lst:
	print(item - l * p, end = " ")