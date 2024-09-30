t = int(input())
for case in range(1, t + 1):
    n = int(input())

    lst = []
    for i in range(n):
        lst.append([0] * n)

    for row in range(n):
        for col in range(n):
            if col == 0:
                lst[row][col] = 1
            elif row == col:
                lst[row][col] = 1

    for row in range(1, n):
        for col in range(1, n):
            lst[row][col] = lst[row-1][col-1] + lst[row-1][col]

    print("#{}".format(case))
    for row in lst:
        for col in row:
            if col != 0:
                print(col, end = " ")
        print()