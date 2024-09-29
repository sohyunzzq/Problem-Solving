from collections import deque

t = int(input())
for i in range(t):
    q = deque()
    n, m = map(int, input().split())
    tmp = list(map(int, input().split()))
    for j in range(n):
        q.append([j, tmp[j]])

    printed = []
    while q:
        candi = []
        for j in range(len(q)):
            candi.append(q[j][1])
        maxi = max(candi)

        while q[0][1] != maxi:
            q.append(q.popleft())
        printed.append(q.popleft())

    for i in range(n):
        if printed[i][0] == m:
            print(i + 1)