count = 1
while True:
	lst = list(map(int, input().split()))
	if len(lst) == 1 and lst[0] == 0:
		break
	print("Case {}: Sorting... done!".format(count))
	count += 1