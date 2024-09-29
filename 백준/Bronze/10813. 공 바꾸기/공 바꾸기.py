n, m = map(int, input().split())
basket = [item for item in range(n + 1)]

for i in range(m):
    x, y = map(int, input().split())
    basket[x], basket[y] = basket[y], basket[x]

for i in range(1, n + 1):
    print(basket[i], end = " ")