n = int(input())
for i in range(n):
	lst = list(input().split())
	num = int(lst[0])
	string = lst[1]

	print(string[0:num-1], end = "")
	print(string[num:len(string)])