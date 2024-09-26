xs = {}
ys = {}
for i in range(3):
	x, y = map(int, input().split())
	if x not in xs:
		xs[x] = 1
	else:
		xs[x] += 1
	if y not in ys:
		ys[y] = 1
	else:
		ys[y] += 1

for key, val in xs.items():
	if val == 1:
		x = key
		break

for key, val in ys.items():
	if val == 1:
		y = key
		break

print(x, y)