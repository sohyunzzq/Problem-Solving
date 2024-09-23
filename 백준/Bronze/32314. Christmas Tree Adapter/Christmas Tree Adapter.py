a = int(input())
w, v = map(int, input().split())

if w >= a * v:
	print(1)
else:
	print(0)