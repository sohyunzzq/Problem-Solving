n = int(input())

dict = {}
lst = list(map(int, input().split()))

for i in lst:
	if i in dict:
		dict[i] += 1
	else:
		dict[i] = 1

v = int(input())

if v in dict:
    print(dict[v])
else:
    print("0")