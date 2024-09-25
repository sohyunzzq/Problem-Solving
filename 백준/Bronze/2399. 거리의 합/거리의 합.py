n = int(input())
lst = list(map(int, input().split()))

ans = 0
for i in range(n):
	for j in range(n):
		ans += abs(lst[i] - lst[j])

print(ans)