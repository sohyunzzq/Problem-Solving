t = int(input())
for i in range(t):
    lst = list(input().split())
    num = float(lst[0])
    for j in range(1, len(lst)):
        cmd = lst[j]
        if cmd == "@":
            num *= 3
        elif cmd == "%":
            num += 5
        else:
            num -= 7

    print("{:.2f}".format(num))