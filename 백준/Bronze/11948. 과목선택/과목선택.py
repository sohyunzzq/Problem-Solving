lst = []
for i in range(4):
	lst.append(int(input()))

ans = sum(lst)
ans -= min(lst)

lst = []
for i in range(2):
	lst.append(int(input()))
ans += max(lst)

print(ans)