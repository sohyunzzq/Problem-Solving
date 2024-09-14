n = int(input())
for i in range(n):
	a, b = input().split()

	if a == b:
		print("OK")
	else:
		print("ERROR")