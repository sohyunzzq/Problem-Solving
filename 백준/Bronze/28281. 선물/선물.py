n, x = map(int, input().split())
price = list(map(int, input().split()))

mini = max(price) * 2 * x
for i in range(n - 1):
	mini = min(mini, price[i] * x + price[i+1] * x)

print(mini)