T = int(input())

for test in range(T):
	a, b = map(int, input().split())
	print("Case #{}: {} + {} = {}".format(test+1, a, b, a+b))