n = int(input())

for case in range(1, n + 1):
    string = input()

    print("#{} ".format(case), end = "")
    if string == string[::-1]:
        print(1)
    else:
        print(0)