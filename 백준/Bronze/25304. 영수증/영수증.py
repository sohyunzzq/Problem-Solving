x = int(input())
n = int(input())

sum1 = 0
for i in range(n):
	a, b = map(int, input().split())
	sum1 += a * b

if sum1 == x:
	print("Yes")
else:
	print("No")