t = int(input())
for i in range(t):
	n = int(input())
	length = len(str(n))
	ten = 10 ** length

	num = n * n
	if num % ten == n:
		print("YES")
	else:
		print("NO")