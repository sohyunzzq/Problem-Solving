from collections import deque

t = int(input())

def in_range(x, y):
    if 0 <= x < n and 0 <= y < n:
        return True
    return False

def can_go(x, y, num):
    if in_range(x, y) and area[x][y] == num + 1 and not visited[x][y]:
        return True
    return False

q = deque()
def bfs():
    global cnt
    while q:
        tmp = q.pop()
        x, y = tmp[0], tmp[1]
        num = area[x][y]

        dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

        for dr in range(4):
            nx, ny = x + dx[dr], y + dy[dr]

            if can_go(nx, ny, num):
                cnt += 1
                q.append([nx, ny])
                visited[nx][ny] = 1


visited = []

for case in range(1, t + 1):
    n = int(input())

    area = []
    for i in range(n):
        area.append(list(map(int, input().split())))

    maxi = 0
    ans = 0
    for row in range(n):
        for col in range(n):
            visited = []
            for i in range(n):
                visited.append([0] * n)

            cnt = 1

            q.append([row, col])
            visited[row][col] = 1
            bfs()

            if cnt == maxi:
                if area[row][col] < ans:
                    ans = area[row][col]
            elif cnt > maxi:
                maxi = cnt
                ans = area[row][col]

    print("#{} {} {}".format(case, ans, maxi))