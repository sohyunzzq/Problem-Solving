n = int(input())
level = []
for i in range(n):
    level.append(int(input()))

if n == 0:
    print(0)
else:
    #절사평균 내기 위해서 위아래에서 cnt명씩 빼면 됨
    if n * 0.15 * 10 % 10 >= 5:
        cnt = int(n * 0.15) + 1
    else:
        cnt = int(n * 0.15)

    level.sort()
    level = level[cnt:n-cnt]

    score = sum(level) / len(level)
    if score * 10 % 10 >= 5:
        score = int(score) + 1
    else:
        score = int(score)

    print(score)