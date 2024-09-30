def in_range(x, y):
    if 0 <= x < h and 0 <= y < w:
        return True
    return False

def shoot(x, y, dr): #x, y에서 dr을 향해서 쏘기
    sx, sy = x, y

    while True:
        nsx, nsy = sx + dx[dr], sy + dy[dr]
        if not in_range(nsx, nsy):
            return

        if area[nsx][nsy] == "*":
            area[nsx][nsy] = "."
            return

        if area[nsx][nsy] == "#":
            return

        sx, sy = nsx, nsy


t = int(input())
for case in range(1, t + 1):
    h, w = map(int, input().split())
    area = []
    for i in range(h):
        area.append(list(input()))

    for i in range(h):
        for j in range(w):
            if area[i][j] == ">":
                x, y = i, j
                dr = 0
                area[i][j] = "."
            elif area[i][j] == "v":
                x, y = i, j
                dr = 1
                area[i][j] = "."
            elif area[i][j] == "<":
                x, y = i, j
                dr = 2
                area[i][j] = "."
            elif area[i][j] == "^":
                x, y = i, j
                dr = 3
                area[i][j] = "."

    n = int(input())
    cmds = input()

    drdict = {"R": 0, "D": 1, "L": 2, "U": 3,
              0: ">", 1: "v", 2: "<", 3: "^"}

    dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]
    for cmd in cmds:
        if cmd == "S":
            shoot(x, y, dr)
        else:
            dr = drdict[cmd]
            nx, ny = x + dx[dr], y + dy[dr]
            if in_range(nx, ny) and area[nx][ny] == ".":
                x, y = nx, ny

    area[x][y] = drdict[dr]

    print("#{} ".format(case), end = "")
    for row in area:
        for col in row:
            print(col, end = "")
        print()