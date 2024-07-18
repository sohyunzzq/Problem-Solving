T = int(input())

for test in range(T):
    H, W, N = map(int, input().split())
    Y = N % H
    if Y == 0:
        Y += H

    X = 1
    for i in range(W):
        if (X - 1) * H + 1 <= N <= X * H:
            break
        X += 1
    if X < 10:
        print(str(Y) + "0" + str(X))
    else:
        print(str(Y) + str(X))