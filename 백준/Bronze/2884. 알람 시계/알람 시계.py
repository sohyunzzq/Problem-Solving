h, m = map(int, input().split())

if m >= 45:
	print("{} {}".format(h, m-45))
elif h == 0:
	print("23 {}".format(m+15))
else:
	print("{} {}".format(h-1, m+15))