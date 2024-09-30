t = int(input())
for case in range(1, t + 1):
    n = int(input())
    alpha = []
    for i in range(n):
        alpha.append(list(input().split()))

    print("#{}".format(case))

    pos = 0
    for i in range(n):
        letter = alpha[i][0]
        num = int(alpha[i][1])

        while num != 0:
            print(letter, end = "")
            pos += 1
            num -= 1

            if pos == 10:
                print()
                pos = 0
    print()