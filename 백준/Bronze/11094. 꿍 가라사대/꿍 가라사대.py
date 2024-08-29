n = int(input())
for i in range(n):
	cmd = input()
	if cmd[0:10] == "Simon says":
		print(cmd[10:len(cmd)])