t = int(input())

for tc in range(1, t+1):

    a, b = map(int, input().split())

    print("#{} ".format(tc), end = "")
    print(int(a/b), a%b)
