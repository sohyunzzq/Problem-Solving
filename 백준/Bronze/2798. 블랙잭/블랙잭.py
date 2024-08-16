n, m = map(int, input().split())
lst = list(map(int, input().split()))

ans = 0
for i in range(n):
	for j in range(i+1, n):
		for k in range(j+1, n):
			tmp = lst[i] + lst[j] + lst[k]
			if tmp <= m:
				ans = max(ans, tmp)
print(ans)