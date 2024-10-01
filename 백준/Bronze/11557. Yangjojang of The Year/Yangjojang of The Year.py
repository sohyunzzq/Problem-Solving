t = int(input())
for case in range(1, t + 1):
    n = int(input())

    lst = []
    for i in range(n):
        tmp = list(input().split())
        name = tmp[0]
        num = int(tmp[1])
        lst.append([name, num])

    lst.sort(key = lambda x: -x[1])

    print(lst[0][0])