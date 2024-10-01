lst = []
for i in range(9):
    lst.append(list(map(int, input().split())))

maxi, r, c = 0, 0, 0

for row in range(9):
    for col in range(9):
        if lst[row][col] >= maxi:
            maxi = lst[row][col]
            r = row + 1
            c = col + 1

print(maxi)
print(r, c)