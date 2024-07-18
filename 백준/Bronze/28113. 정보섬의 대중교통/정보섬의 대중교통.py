n, a, b = map(int, input().split())

if a > b:
	print("Subway")
elif b > a:
	print("Bus")
else:
	print("Anything")