n = int(input())

mini = n
for i in range(n // 5 + 1):
    if (n - 5 * i) % 3 == 0:
        mini = min(mini, i + (n - 5 * i) // 3)

if mini == n:
    print(-1)
else:
    print(mini)