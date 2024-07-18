dict1 = {}
for i in range(10):
	n = int(input()) % 42
	if n in dict1:
		dict1[n] += 1
	else:
		dict1[n] = 1

print(len(dict1))