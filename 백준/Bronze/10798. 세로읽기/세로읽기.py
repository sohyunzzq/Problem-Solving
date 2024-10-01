lst = []
for i in range(5):
    lst.append(["."] * 15)

for i in range(5):
    tmp = input()
    for j in range(len(tmp)):
        lst[i][j] = tmp[j]

ans = []

for col in range(15):
    for row in range(5):
        if lst[row][col] != ".":
            ans.append(lst[row][col])

for item in ans:
    print(item, end="")