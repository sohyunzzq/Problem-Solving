n = int(input())
ans = 0
for i in range(n):
	gifticon = input()
	if int(gifticon[2:len(gifticon)]) <= 90:
		ans += 1

print(ans)