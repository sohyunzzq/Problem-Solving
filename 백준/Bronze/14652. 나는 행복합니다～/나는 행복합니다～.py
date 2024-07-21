n, m, k = map(int, input().split())

y = k % m

for i in range(0, n):
	if m*i <= k < m*(i+1):
		x = i

print(x, y)