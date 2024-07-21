def check(arrive, attack, sleep):
	time = 1
	while True:
		if arrive in range(time, time + attack):
			return 1
		elif arrive in range(time + attack, time + attack + sleep):
			return 0

		time += attack + sleep
		
a, b, c, d = map(int, input().split())
p, m, n = map(int, input().split())

print(check(p, a, b) + check(p, c, d))
print(check(m, a, b) + check(m, c, d))
print(check(n, a, b) + check(n, c, d))