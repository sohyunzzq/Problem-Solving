while True:
	n = float(input())
	if n == 0: break
	
	print("{:.2f}".format(1+n+n*n+n*n*n+n*n*n*n))