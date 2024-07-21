x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())

len1 = max(x2, x4) - min(x1, x3)
len2 = max(y2, y4) - min(y1, y3)

print(max(len1, len2)**2)