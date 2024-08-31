def tic():
	for i in range(1, n+1):
		if i not in dict1:
			print(i)
			return
	print(n+1)
	return


n = int(input())
ticket = list(map(int, input().split()))

dict1 = {}
for item in ticket:
	dict1[item] = 0

tic()