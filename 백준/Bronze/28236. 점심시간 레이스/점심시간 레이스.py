n, m, k = map(int, input().split())

ans = k
shortest = n * m

for i in range(k):
	f, d = map(int, input().split())

	time = f - 1 + m - d
	
	if time < shortest:
		shortest = time
		ans = i+1

print(ans)