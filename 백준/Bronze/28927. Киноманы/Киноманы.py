t1, e1, f1 = map(int, input().split())
Ma = t1 * 3 + e1 * 20 + f1 * 120

t2, e2, f2 = map(int, input().split())
Me = t2 * 3 + e2 * 20 + f2 * 120

if Ma > Me:
	print("Max")
elif Me > Ma:
	print("Mel")
else:
	print("Draw")