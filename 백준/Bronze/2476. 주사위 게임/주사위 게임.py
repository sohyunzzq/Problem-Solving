n = int(input())
lst = []
for i in range(n):
    a, b, c = map(int, input().split())

    money = 0
    if a == b == c:
        money += 10000 + a * 1000
    elif a == b or b == c:
        money += 1000 + b * 100
    elif a == c:
        money += 1000 + a * 100
    else:
        money += max(a, b, c) * 100

    lst.append(money)

print(max(lst))