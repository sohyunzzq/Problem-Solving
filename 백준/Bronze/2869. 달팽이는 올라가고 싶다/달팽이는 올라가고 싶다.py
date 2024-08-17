a, b, v = map(int, input().split())

v -= a

if v % (a-b) == 0:
	print(v//(a-b) + 1)
else:
	print(v//(a-b) + 2)