n = int(input())
for i in range(n):
	a, b, c = map(float, input().split())
	print("${:.2f}".format(a*b*c))