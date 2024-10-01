s = int(input())
sum1 = 0
num = []
for i in range(1, s + 1):
    sum1 += i
    num.append(i)

    if sum1 == s:
        print(len(num))
        break
    if sum1 > s:
        print(len(num) - 1)
        break