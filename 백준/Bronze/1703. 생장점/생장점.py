while True:
	tree = list(map(int, input().split()))
	if tree[0] == 0:
		break

	level = tree[0]
	leaf = 1
	for i in range(1, 2 * level, 2):
		leaf *= tree[i]
		leaf -= tree[i+1]
	print(leaf)