n = int(input())

ans = 0

for b in range(1, 501):
	for a in range(b, 501):
		if a * a == b * b + n:
			ans += 1

print(ans)