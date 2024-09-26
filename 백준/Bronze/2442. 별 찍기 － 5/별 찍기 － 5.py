n = int(input())
for i in range(n):
	print(" " * (n-i-1), end = "")
	print("*" * (i*2+1))