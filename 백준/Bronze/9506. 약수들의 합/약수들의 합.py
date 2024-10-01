def get(num):
    lst = []
    for i in range(1, num):
        if num % i == 0:
            lst.append(i)

    check(num, lst)

def check(num, lst):
    if sum(lst) == num:
        print("{} = {}".format(num, lst[0]), end = "")
        for i in range(1, len(lst)):
            print(" + {}".format(lst[i]), end = "")
        print()
    else:
        print("{} is NOT perfect.".format(num))

while True:
    n = int(input())
    if n == -1:
        break

    get(n)