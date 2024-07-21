y1, m1, d1 = map(int, input().split())
y2, m2, d2 = map(int, input().split())

if y1 == y2:
	print(0)
elif m1 > m2 or (m1 == m2 and d1 > d2):
	print(y2 - y1 - 1)
else:
	print(y2 - y1)

print(y2 - y1 + 1)
print(y2 - y1)