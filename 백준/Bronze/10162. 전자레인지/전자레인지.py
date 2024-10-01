t = int(input())
a, b, c = 300, 60, 10
c1, c2, c3 = 0, 0, 0

c1 = t // a
t %= a

c2 = t // b
t %= b

c3 = t // c
t %= c

if t != 0:
    print(-1)
else:
    print(c1, c2, c3)