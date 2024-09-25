n = int(input())

res = 1
for i in range(1, n + 1):
	res *= i

res = str(res)[::-1]

ans = 0
for item in res:
	if item == "0":
		ans += 1
	else:
		print(ans)
		break