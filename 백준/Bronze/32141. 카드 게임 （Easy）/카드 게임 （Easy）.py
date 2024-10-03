n, h = map(int, input().split())
card = list(map(int, input().split()))

if sum(card) < h:
    print(-1)
else:
    sum1 = 0
    for i in range(n):
        sum1 += card[i]
        if sum1 >= h:
            print(i + 1)
            break