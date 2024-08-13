def check():
	for i in range(1, n-1):
		if lst[i] - lst[i-1] != lst[i+1] - lst[i]:
			return "mul"
		else:
			return "add"

n = int(input())

lst = []
for i in range(n):
	lst.append(int(input()))

if check() == "mul":
	print(lst[n-1] * lst[1] // lst[0])
else:
	print(lst[n-1] + (lst[1] - lst[0]))