n = int(input())
mini = 200
for i in range(n):
	a, b = map(int, input().split())
	mini = min(mini, a + b)

print(mini)