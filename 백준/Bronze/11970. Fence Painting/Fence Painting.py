lst = [0] * 101

a, b = map(int, input().split())
c, d = map(int, input().split())

for i in range(a, b):
	lst[i] = 1
for i in range(c, d):
	lst[i] = 1

print(sum(lst))