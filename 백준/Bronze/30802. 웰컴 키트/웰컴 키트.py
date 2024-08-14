n = int(input())
tshirts = list(map(int, input().split()))
t, p = map(int, input().split())

#티셔츠는 남아도 되지만 부족 안 됨
#펜은 딱 맞춰야 됨

cnt = 0
for size in tshirts:
	tmp = size // t
	cnt += tmp + 1
	if size % t == 0:
		cnt -= 1
print(cnt)

print(n // p, n % p)