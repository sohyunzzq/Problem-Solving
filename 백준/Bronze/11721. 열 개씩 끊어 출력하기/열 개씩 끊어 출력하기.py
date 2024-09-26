string = input()
for i in range(len(string) // 10 + 1):
	if (i+1) * 10 > len(string):
		print(string[i*10:len(string)])
	else:
		print(string[i*10:(i+1)*10])