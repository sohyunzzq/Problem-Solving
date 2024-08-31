def soccer():
	for a in range(sum1 + 1):
		b = sum1 - a
		if b - a == sub1:
			print(b, a)
			return
	print(-1)
	return

sum1, sub1 = map(int, input().split())
soccer()