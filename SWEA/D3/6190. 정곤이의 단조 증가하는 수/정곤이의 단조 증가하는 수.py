def check(a):
    for i in range(len(a) - 1):
        if a[i] > a[i+1]:
            return False
    return True

t = int(input())
for case in range(1, t + 1):
    n = int(input())
    num = list(map(int, input().split()))

    lst = []
    for i in range(n):
        for j in range(i+1, n):
            if check(str(num[i] * num[j])):
                lst.append(num[i] * num[j])

    if not lst:
        print("#{} -1".format(case))
    else:
        print("#{} {}".format(case, max(lst)))