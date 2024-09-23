lst = ["", "ABCDEFGHJLM", "ACEFGHILM", "ACEFGHILM", "ABCEFGHLM", "ACEFGHLM", "ACEFGHLM", "ACEFGHLM", "ACEFGHLM", "ACEFGHLM", "ABCFGHLM"]

n = int(input())

print(len(lst[n]))
for letter in lst[n]:
	print(letter, end = " ")