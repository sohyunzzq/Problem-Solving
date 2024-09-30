t = int(input())
for case in range(1, t + 1):
    n = int(input())
    lst = []
    for i in range(n):
        lst.append([])

    for i in range(n):
        string = input()
        for letter in string:
            lst[i].append(int(letter))

    ans = 0
    for row in range(n // 2 + 1):
        for col in range(n // 2 - row, n // 2 - row + 2 * row + 1):
            ans += lst[row][col]

    for row in range(n // 2 + 1, n):
        for col in range(row - n // 2, n - (row - n // 2)):
            ans += lst[row][col]

    print("#{} {}".format(case, ans))