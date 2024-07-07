T = int(input())
for i in range(1, T+1):
    total = 0
    n = input().split(' ')

    for j in n:
        if int(j) % 2 == 1:
            total += int(j)
    print("#%s %s" % (i, total))