n, m = map(int, input().split())

basket = [0] * (n+1)
for i in range(m):
	a, b, c = map(int, input().split())
	for j in range(a, b+1):
		basket[j] = c

for i in range(1, n+1):
	print(basket[i], end = " ")