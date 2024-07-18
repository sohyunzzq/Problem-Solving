n = int(input())
result = 0

lst = list(map(int, input().split()))

for i in lst:
	result += i

if result > 0:
	print("Right")
elif result < 0:
	print("Left")
else:
	print("Stay")