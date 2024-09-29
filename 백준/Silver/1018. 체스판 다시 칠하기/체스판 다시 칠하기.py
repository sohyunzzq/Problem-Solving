def chess(x, y):
    mini = n * m
    ### 흰색으로 시작
    cnt = 0
    for row in range(x, x + 8):
        for col in range(y, y + 8):
            if row % 2 == 0:
                if col % 2 == 0:
                    if area[row][col] != "W":
                        cnt += 1
                else:
                    if area[row][col] != "B":
                        cnt += 1
            else:
                if col % 2 == 0:
                    if area[row][col] != "B":
                        cnt += 1
                else:
                    if area[row][col] != "W":
                        cnt += 1
    mini = min(mini, cnt)

    ### 검정색으로 시작
    cnt = 0
    for row in range(x, x + 8):
        for col in range(y, y + 8):
            if row % 2 == 0:
                if col % 2 == 0:
                    if area[row][col] != "B":
                        cnt += 1
                else:
                    if area[row][col] != "W":
                        cnt += 1
            else:
                if col % 2 == 0:
                    if area[row][col] != "W":
                        cnt += 1
                else:
                    if area[row][col] != "B":
                        cnt += 1
    mini = min(mini, cnt)

    return mini

n, m = map(int, input().split())
area = []
for i in range(n):
    area.append(list(input()))

mini = n * m
for row in range(n - 8 + 1):
    for col in range(m - 8 + 1):
        mini = min(chess(row, col), mini)

print(mini)