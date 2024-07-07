T = int(input())
for i in range(1, T+1):
    n = list(map(int, input().split(' ')))

    if n[0] > n[1]:
        print("#%s >" % i)
    elif n[0] == n[1]:
        print("#%s =" % i)
    else:
        print("#%s <" % i)