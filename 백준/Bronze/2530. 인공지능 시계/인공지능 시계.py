h, m, s = map(int, input().split())
time = int(input())

s += time

while s >= 60:
	s -= 60
	m += 1

while m >= 60:
	m -= 60
	h += 1

while h >= 24:
	h -= 24

print(h, m, s)