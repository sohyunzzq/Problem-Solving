a, b, v = map(int, input().split())

v -= a
ans = 1

if v % (a-b) == 0:
	print(v//(a-b) + ans)
else:
	print(v//(a-b) +1 +ans)

'''
2 1 4

2

하루에 올라가는 높이 a - b
2
-1+2
-1+2

2+1+1
///

18
5+4+4+4+4
5

13
4+4+4+4

13/4

'''