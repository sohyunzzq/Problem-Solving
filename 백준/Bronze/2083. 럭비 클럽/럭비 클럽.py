while True:
	str1 = input()
	if str1 == "# 0 0":
		break

	name, age, w = str1.split()

	if int(age) > 17 or int(w) >= 80:
		print("{} Senior".format(name))
	else:
		print("{} Junior".format(name))