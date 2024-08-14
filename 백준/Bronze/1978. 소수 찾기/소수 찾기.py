def prime(num):
	if num < 2:
		return 0
	for i in range(2, num):
		if num % i == 0:
			return 0
	return 1

n = int(input())
lst = list(map(int, input().split()))

ans = 0
for i in range(n):
	ans += prime(lst[i])
print(ans)