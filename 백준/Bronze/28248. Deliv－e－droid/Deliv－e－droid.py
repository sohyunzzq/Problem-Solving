p = int(input())
c = int(input())

total = 0
total += p * 50 - c * 10
if p > c:
	total += 500

print(total)