n = int(input())
black = []
for i in range(n):
    black.append(list(map(int, input().split())))

white = []
for i in range(101):
    white.append([0] * 101)

for coor in black:
    x, y = coor[0], coor[1]

    for row in range(y, y + 10):
        white[row][x:x + 10] = [1] * 10

ans = 0
for row in range(101):
    ans += sum(white[row])

print(ans)