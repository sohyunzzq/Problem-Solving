n = int(input())
a, b, c = map(int, input().split())

cnt = 0

if a < n:
	cnt += a
elif a >= n:
	cnt += n

if b < n:
	cnt += b
elif b >= n:
	cnt += n

if c < n:
	cnt += c
elif c >= n:
	cnt += n

print(cnt)