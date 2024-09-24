k = int(input())
lst = []
for i in range(k):
	n = int(input())
	if n == 0:
		lst.pop()
	else:
		lst.append(n)

print(sum(lst))