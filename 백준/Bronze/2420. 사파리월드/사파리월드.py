a, b = map(int, input().split())

res = a - b
if res < 0:
	res = -res

print(res)