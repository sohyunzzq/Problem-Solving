n, k = map(int, input().split())
lst = []

for i in range(1, n+1):
	if i % 10 == k % 10 or i % 10 == (2 * k) % 10:
		continue
	lst.append(i)

print(len(lst))
for item in lst:
	print(item, end = " ")