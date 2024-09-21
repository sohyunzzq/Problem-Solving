def mul(n):
	ret = 1
	for i in range(len(n)):
		ret *= int(n[i])
	return str(ret)

n = input()

ans = 0
while len(n) > 1:
	n = mul(n)
	ans += 1

print(ans)