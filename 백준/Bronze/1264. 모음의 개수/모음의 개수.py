while True:
	str1 = input()
	if str1 == "#":
		break
	
	cnt = 0
	for i in str1:
		if i in "aeiouAEIOU":
			cnt += 1
	print(cnt)