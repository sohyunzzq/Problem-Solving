n = int(input())
lst = []
for i in range(n):
    lst.append(list(map(int, input().split())))

bigger = [0] * n

for i in range(n):
    for j in range(i + 1, n):
        if lst[i][0] < lst[j][0] and lst[i][1] < lst[j][1]:
            bigger[i] += 1
        elif lst[i][0] > lst[j][0] and lst[i][1] > lst[j][1]:
            bigger[j] += 1

for item in bigger:
    print(item + 1, end = " ")