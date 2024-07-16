def add(lst):
	total = 0
	total += lst[0]*6 + lst[1]*3 + lst[2]*2 + lst[3]*1 + lst[4]*2
	return total

lst1 = list(map(int, input().split()))
lst2 = list(map(int, input().split()))

print(add(lst1), add(lst2))