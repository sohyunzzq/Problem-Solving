month = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def correct(date):
    if 1 <= int(date[4:6]) <= 12:
        if 1 <= int(date[6:8]) <= month[int(date[4:6])]:
            return True
    return False

T = int(input())

for i in range(1, T+1):
    date = input()

    if correct(date):
        print("#%s %s/%s/%s" % (i, date[0:4], date[4:6], date[6:8]))
    else:
        print("#%s -1" % i)