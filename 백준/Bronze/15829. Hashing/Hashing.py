L = int(input())
alpha = input()

ans = 0
for i in range(L):
	ans += (ord(alpha[i].upper()) - 64) * 31 ** i
	ans %= 1234567891
print(ans)