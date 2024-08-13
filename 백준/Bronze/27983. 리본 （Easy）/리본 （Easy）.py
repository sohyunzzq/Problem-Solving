def ribbon():
	for i in range(n):
		for j in range(i+1, n):
			if abs(int(lst[i][0]) - int(lst[j][0])) <= int(lst[i][1]) + int(lst[j][1]) and lst[i][2] != lst[j][2]:
				print("YES")
				print(i+1, j+1)
				return
	print("NO")

n = int(input())
lst = []
for i in range(n):
	lst.append([])

for i in range(3):
	tmp = list(input().split())	
	for j in range(n):
		lst[j].append(tmp[j])

ribbon()