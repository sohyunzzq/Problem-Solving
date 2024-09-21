y, m, d = map(int, input().split("-"))
n = int(input())

d += n

m += d // 30
d %= 30

if d == 0:
	d = 30
	m -= 1

y += m // 12
m %= 12

if m == 0:
	m = 12
	y -= 1

print("{}-".format(y), end = "")
if m < 10:
	print("0{}-".format(m), end = "")
else:
	print("{}-".format(m), end = "")
if d < 10:
	print("0{}".format(d), end = "")
else:
	print("{}".format(d), end = "")