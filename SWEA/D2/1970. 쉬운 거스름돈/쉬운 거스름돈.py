t = int(input())
for case in range(1, t + 1):
    price = int(input())

    dict1 = {50000: 0, 10000: 0, 5000: 0, 1000: 0, 500: 0, 100: 0, 50: 0, 10: 0}

    for key in dict1.keys():
        if price >= key:
            dict1[key] = price // key
            price %= key

    print("#{}".format(case))
    for value in dict1.values():
        print(value, end = " ")
    print()