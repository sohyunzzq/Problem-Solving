t = int(input())
for case in range(1, t + 1):
    y, k = 0, 0
    for i in range(9):
        a, b = map(int, input().split())
        y += a
        k += b

    if y > k:
        print("Yonsei")
    elif y < k:
        print("Korea")
    else:
        print("Draw")