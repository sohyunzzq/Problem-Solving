T = int(input())

for test in range(T):
	quiz = input()
	score = 0
	s = 1

	for i in quiz:
		if i == "O":
			score += s
			s += 1
		else:
			s = 1
	print(score)