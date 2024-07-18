n = int(input())
odd = 0
even = 0
lst = list(map(int, input().split()))

for i in lst:
	if i % 2 == 0:
		even += 1
	else:
		odd += 1

if even > odd:
	print("Happy")
else:
	print("Sad")