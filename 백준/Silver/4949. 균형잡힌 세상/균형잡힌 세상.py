def check():
	lst = []
	for letter in string:
		if letter == "(" or letter == "[":
			lst.append(letter)

		elif letter == ")":
			if len(lst) == 0:
				return False
			if lst[-1] == "(":
				lst.pop()
			else:
				return False

		elif letter == "]":
			if len(lst) == 0:
				return False
			if lst[-1] == "[":
				lst.pop()
			else:
				return False
	if len(lst) == 0:
		return True	

while True:
	string = input()
	if string == ".":
		break
	
	if check():
		print("yes")
	else:
		print("no")