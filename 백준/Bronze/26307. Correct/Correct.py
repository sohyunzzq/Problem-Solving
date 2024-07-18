h, m = map(int, input().split())

result = 0

while h != 9:
	h -= 1
	result += 60

if m != 0:
	result += m
print(result)