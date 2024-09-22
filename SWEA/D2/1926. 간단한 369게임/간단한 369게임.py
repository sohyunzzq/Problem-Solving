def clap(num):
	num = str(num)
	cnt = 0
	for i in range(len(num)):
		if num[i] in "369":
			cnt += 1

	if cnt == 0:
		return False

	for i in range(cnt):
		print("-", end = "")
	print("", end = " ")
	return True

n = int(input())
for i in range(1, n+1):
	if not clap(i):
		print(i, end = " ")