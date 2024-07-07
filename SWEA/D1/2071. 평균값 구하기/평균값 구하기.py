T = int(input())
for i in range(1, T+1):
    total = 0
    n = list(map(int, input().split(' ')))
    #n = input().split(' ')

    for j in n:
        total += int(j)
    print("#%s %.0f" % (i, total/10))