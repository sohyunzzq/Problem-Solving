import sys

n = int(sys.stdin.readline().rstrip())

lst = [0] * 10001

for i in range(n):
	k = int(sys.stdin.readline().rstrip())
	lst[k] += 1

for i, j in enumerate(lst):
	if j > 0:
		for k in range(j):
			sys.stdout.write(str(i) + '\n')