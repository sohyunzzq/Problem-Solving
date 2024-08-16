def gcd(a, b):
	for i in range(b, 0, -1):
		if a % i == 0 and b % i == 0:
			return i

def lcm(a, b):
	for i in range(a, a*b+1, a):
		if i % b == 0:
			return i

a, b = map(int, input().split())

if b > a:
	b, a = a, b
print(gcd(a, b), lcm(a, b))