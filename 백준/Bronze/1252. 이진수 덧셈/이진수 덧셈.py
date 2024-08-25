def btod(num): #이진수에서 십진수
	if num == "0":
		return 0
	dec = 1
	for i in range(1, len(num)):
		dec = dec * 2 + int(num[i])
	return dec

def dtob(num): #십진수에서 이진수
	if num == 0:
		return 0
	bi = ""
	while num > 0:
		bi = str(num % 2) + bi
		num //= 2
	
	return bi

a, b = input().split()

while True:
	if len(a) == 1 and a[0] == "0":
		break
	if a[0] == "1":
		break
	a = a[1:]

while True:
	if len(b) == 1 and b[0] == "0":
		break
	if b[0] == "1":
		break
	b = b[1:]

a, b = btod(a), btod(b)

ans = dtob(a + b)

print(ans)