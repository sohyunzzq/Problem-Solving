n = int(input())
for i in range(n):
	string = input()
	if string[-1] != ".":
		string += "."
	print(string)