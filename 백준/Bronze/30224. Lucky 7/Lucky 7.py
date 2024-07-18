n = input()

if "7" in n:
	if int(n) % 7 == 0:
		print("3")
	else:
		print("2")
else:
	if int(n) % 7 == 0:
		print("1")
	else:
		print("0")