n = int(input())

num = 666
cnt = 1
while True:
    if cnt == n:
        print(num)
        break
    else:
        num += 1
        if "666" in str(num):
            cnt += 1