T = int(input())
for i in range(T):
    lst = list(map(int, input().split()))
    print("#%s %s %s" % (i+1, lst[0] // lst[1], lst[0] % lst[1]))