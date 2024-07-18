n = int(input())
result = 0

for i in range(1, n+1):
	result += i
print(result)

print(result*result)

result = 0
for i in range(1, n+1):
	result += i**3
print(result)