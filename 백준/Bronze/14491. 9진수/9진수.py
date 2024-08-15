n = int(input())
result = ""

while n:
	result = str(n % 9) + result
	n //= 9

print(result)