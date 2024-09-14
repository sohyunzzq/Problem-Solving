def dec_2_bin(num):
	if num == 0:
		return "0000000000"

	result = ""
	while num:
		result = str(num % 2) + result
		num //= 2

	while len(result) != 10:
		result = "0" + result

	return result

def bin_2_dec(num):
	ans = 0
	for i in range(len(str(num))):
		ans = ans * 2 + int(str(num)[i])
	
	return ans

a, b = map(int, input().split())

a = dec_2_bin(a)
b = dec_2_bin(b)
c = ""
for i in range(10):
	if a[i] != b[i]:
		c += "1"
	else:
		c += "0"

c = bin_2_dec(int(c))
print(c)