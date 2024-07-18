lst = []
for i in range(9):
	lst.append(int(input()))

print(sorted(lst)[8])

for i in range(9):
	if sorted(lst)[8] == lst[i]:
		print(i+1)