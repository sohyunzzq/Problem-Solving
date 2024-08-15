dirc = {0: "N", 1: "E", 2: "S", 3: "W"}

x = 0
for i in range(10):
	cmd = int(input())

	if cmd == 1:
		x = (x + 1) % 4
	elif cmd == 2:
		x = (x + 2) % 4
	else:
		x = (x - 1) % 4

print(dirc[x])