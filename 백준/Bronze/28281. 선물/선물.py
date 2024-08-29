N, X = map(int, input().split())
d = list(map(int, input().split()))
minimum = 9876543210
for i in range(N - 1):
    c = (d[i] + d[i + 1]) * X
    minimum = min(c, minimum)
print(minimum)
