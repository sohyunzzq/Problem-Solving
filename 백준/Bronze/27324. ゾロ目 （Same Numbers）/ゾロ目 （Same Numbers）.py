n = input()

flag = 0
for i in range(len(n)):
	for j in range(len(n)):
		if n[i] != n[j] and flag != 1:
			print("0")
			flag = 1
if flag == 0:
	print("1")