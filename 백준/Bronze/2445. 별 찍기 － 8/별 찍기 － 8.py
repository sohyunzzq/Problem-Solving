n = int(input())
for i in range(n):
	print("*" * (i+1), end = "")
	print(" " * (n-i-1), end = "")
	print(" " * (n-i-1), end = "")
	print("*" * (i+1))

for i in range(1, n):
	print("*" * (n-i), end = "")
	print(" " * i, end = "")
	print(" " * i, end = "")	
	print("*" * (n-i))