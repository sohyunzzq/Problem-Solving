n = int(input())
print(n, end = "")

while n != 1:
	if n % 2 == 0: #even
		n //= 2
	else:
		n = n * 3 + 1
	
	print(" {}".format(n), end = "")