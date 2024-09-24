def check():
	lst = []

	for letter in string:
		if letter == "(":
			lst.append(letter)
		else:
			if len(lst) == 0:
				return False
			lst.pop()
	if len(lst) == 0:
		return True

n = int(input())
for i in range(n):
	string = input()

	if check():
		print("YES")
	else:
		print("NO")