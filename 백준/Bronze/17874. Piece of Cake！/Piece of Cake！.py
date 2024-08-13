n, h, v = map(int, input().split())

print(max(h * v, (n-h) * v, h * (n-v), (n-h) * (n-v)) * 4)