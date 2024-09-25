from collections import deque

n = int(input())

q = deque()
for i in range(n):
	cmd = list(input().split())
	if cmd[0] == "push":
		num = cmd[1]
	cmd = cmd[0]

	if cmd == "push":
		q.append(num)
	elif cmd == "pop":
		if len(q) == 0:
			print(-1)
		else:
			print(q[0])
			q.popleft()
	elif cmd == "size":
		print(len(q))
	elif cmd == "empty":
		if len(q) == 0:
			print(1)
		else:
			print(0)
	elif cmd == "front":
		if len(q) == 0:
			print(-1)
		else:
			print(q[0])
	else:
		if len(q) == 0:
			print(-1)
		else:
			print(q[-1])