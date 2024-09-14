n = int(input())
ans = 0
for i in range(n):
	tmp = input()
	if tmp[0] == "-":
		ans -= int(tmp[1:len(tmp)])
	else:
		ans += int(tmp)

print(ans)