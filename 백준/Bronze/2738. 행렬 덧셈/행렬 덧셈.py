N, M = map(int, input().split())
result = []

for i in range(N):
	result.append([0]*M)



for i in range(N):
	lst = list(map(int, input().split()))
	for j in range(M):
		result[i][j] += lst[j]

for i in range(N):
	lst = list(map(int, input().split()))
	for j in range(M):
		result[i][j] += lst[j]


for i in range(N):
	for j in range(M):
		print(result[i][j], end = " ")