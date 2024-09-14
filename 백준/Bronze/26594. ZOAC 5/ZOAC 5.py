def keyboard():
	for i in range(1, len(string)):
		if string[i-1] != string[i]:
			print(i)
			return
	print(len(string))
	return

string = input()
keyboard()