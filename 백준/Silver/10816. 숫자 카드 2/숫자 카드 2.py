n = int(input())
lst = list(map(int, input().split()))

card = {}
for item in lst:
	if item not in card:
		card[item] = 1
	else:
		card[item] += 1

m = int(input())
lst = list(map(int, input().split()))

for item in lst:
	if item not in card:
		print(0, end = " ")
	else:
		print(card[item], end = " ")