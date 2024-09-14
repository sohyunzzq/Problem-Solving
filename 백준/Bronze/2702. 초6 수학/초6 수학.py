def lcm(a, b): #최소공배수
	if b > a:
		a, b = b, a

	for i in range(a, a*b+1, a):
		if i % b == 0:
			return i

def gcd(a, b): #최대공약수
	if b > a:
		a, b = b, a

	for i in range(b, 0, -1):
		if a % i == 0 and b % i == 0:
			return i

n = int(input())
for i in range(n):
	a, b = map(int, input().split())

	ans1 = lcm(a, b)
	ans2 = gcd(a, b)
	print(ans1, ans2)