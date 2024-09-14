n = int(input())
for i in range(n):
	year = int(input())
	if (year + 1) % (year % 100) == 0:
		print("Good")
	else:
		print("Bye")