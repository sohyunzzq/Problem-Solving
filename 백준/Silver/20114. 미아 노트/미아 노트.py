n, h, w = map(int, input().split())
ans = ["?"] * n

for i in range(h):
	letter = input()
	for j in range(n * w):
		if letter[j] != "?":
			ans[j // w] = letter[j]

for item in ans:
	print(item, end = "")