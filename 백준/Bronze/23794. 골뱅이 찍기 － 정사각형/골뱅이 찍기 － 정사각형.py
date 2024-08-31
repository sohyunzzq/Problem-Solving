n = int(input())

for i in range(n+2):
	if i == 0 or i == n + 1:
		print("@" * (n+2))
	else:
		print("@", end = "")
		print(" " * n, end = "")
		print("@", end = "")
		print()