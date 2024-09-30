from collections import deque

for _ in range(10):
    t = int(input())
    q = deque()
    tmp = list(map(int, input().split()))

    for item in tmp:
        q.append(item)

    while 0 not in q:
        for i in range(1, 6):
            num = q.popleft()
            if num - i <= 0:
                num = 0
                q.append(num)
                break

            q.append(num - i)

    print("#{} ".format(t))
    for item in q:
        print(item, end = " ")
    print()