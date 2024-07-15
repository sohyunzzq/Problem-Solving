R, B = map(int, input().split())

n = R+B

for i in range(n-1, 0, -1):
	if n % i == 0 and (i-2)*(int(n/i)-2) == B:
		print(i, int(n/i))
		break