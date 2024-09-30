def possibility():
    if guest[0] == 0:
        return False

    bread = [0] * (max(guest) + 3)

    for t in range(m, max(guest) + 1, m):
        bread[t] += k

    for t in range(max(guest) + 1):
        if t in guest:
            if bread[t] == 0:
                return False
            bread[t] -= 1

        bread[t + 1] += bread[t]
    return True


t = int(input())
for case in range(1, t + 1):
    n, m, k = map(int, input().split())
    guest = list(map(int, input().split()))
    guest.sort()

    print("#{}".format(case), end = " ")
    if possibility():
        print("Possible")
    else:
        print("Impossible")