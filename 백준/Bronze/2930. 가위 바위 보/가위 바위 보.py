def score(tmp):
	maxi = 0

	for letter in "SPR":
		sum = 0
		for i in range(n):
			if tmp[i] == dict1[letter]:
				sum += 2
			elif tmp[i] == letter:
				sum += 1
		
			maxi = max(maxi, sum)

	return maxi

dict1 = {"S": "P", "P": "R", "R": "S"}

r = int(input())
mine = input()
friends = []
n = int(input())
for i in range(n):
	friends.append(input())

s = 0
for i in range(n):
	for j in range(r):
		if friends[i][j] == dict1[mine[j]]:
			s += 2
		elif friends[i][j] == mine[j]:
			s += 1
print(s)

s = 0
for j in range(r):
	tmp = []
	for i in range(n):
		tmp.append(friends[i][j])
	
	s += score(tmp)
print(s)