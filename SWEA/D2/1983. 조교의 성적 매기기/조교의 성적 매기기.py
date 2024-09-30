rank = ["A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"]

t = int(input())
for case in range(1, t + 1):
    n, k = map(int, input().split())

    score = []
    for i in range(n):
        score.append([i + 1, 0, ""])
    for i in range(n):
        a, b, c = map(int, input().split())
        score[i][1] = a * 0.35 + b * 0.45 + c * 0.2

    score.sort(key = lambda x: -x[1])

    for i in range(n):
        score[i][2] = rank[i // (n // 10)]

    for i in range(n):
        if score[i][0] == k:
            ans = score[i][2]
            break

    print("#{} {}".format(case, ans))