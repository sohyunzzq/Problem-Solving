n = int(input())
lst = []
for i in range(n):
	cmd = list(input().split())
	if cmd[0] == "push":
		num = cmd[1]
	cmd = cmd[0]

	if cmd == "push":
		lst.append(num)
	elif cmd == "pop":
		if len(lst) == 0:
			print(-1)
		else:
			print(lst.pop())
	elif cmd == "size":
		print(len(lst))
	elif cmd == "empty":
		if len(lst) == 0:
			print(1)
		else:
			print(0)
	else:
		if len(lst) == 0:
			print(-1)
		else:
			print(lst[-1])