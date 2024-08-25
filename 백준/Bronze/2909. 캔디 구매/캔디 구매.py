a, b = map(int, input().split())

money = 10 ** b

if b == 0:
	print(a)

elif a % money >= money // 2 :
	print(a + (money - a%money))
else:
	print(a - a%money)