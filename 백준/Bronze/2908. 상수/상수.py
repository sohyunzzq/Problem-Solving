a, b = input().split()

if int(a[::-1]) < int(b[::-1]):
	print(b[::-1])
else:
	print(a[::-1])