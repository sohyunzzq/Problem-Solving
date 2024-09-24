n = int(input())
lst = set(map(int, input().split()))

m = int(input())
find_lst = list(map(int, input().split()))
for num in find_lst:
	if num in lst:
		print(1)
	else:
		print(0)