n = int(input())
for i in range(n):
	name = input()
	for j in range(len(name)):
		print(name[j].lower(), end = "")
	print()
