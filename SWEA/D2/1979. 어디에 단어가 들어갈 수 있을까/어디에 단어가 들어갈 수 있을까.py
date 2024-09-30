def count(lst):
    cnt = 0
    for row in range(n):
        for col in range(n - k + 1):
            if lst[row][col:col + k] == [1] * k:
                if n == k:
                    cnt += 1
                elif col == 0:
                    if lst[row][col + k] == 0:
                        cnt += 1
                elif col == n - k:
                    if lst[row][col - 1] == 0:
                        cnt += 1
                else:
                    if lst[row][col + k] == 0 and lst[row][col - 1] == 0:
                        cnt += 1

    return cnt

t = int(input())
for case in range(1, t + 1):
    n, k = map(int, input().split())
    lst = []
    for i in range(n):
        lst.append(list(map(int, input().split())))

    ans = 0
    ans += count(lst)

    rotate = []
    for i in range(n):
        rotate.append([0] * n)

    for i in range(n):
        for j in range(n):
            rotate[i][j] = lst[j][i]

    ans += count(rotate)

    print("#{} {}".format(case, ans))