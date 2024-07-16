lst = list(map(int, input().split()))
for i in range(8):
	if lst[i] == 9:
		print("F")
		break
if i == 7 and lst[7] != 9:
	print("S")