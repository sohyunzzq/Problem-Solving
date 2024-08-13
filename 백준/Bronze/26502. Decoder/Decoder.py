dict1 = {"y": "a", "a": "e", "e": "i", "i": "o", "o": "u", "u": "y",
         "Y": "A", "A": "E", "E": "I", "I": "O", "O": "U", "U": "Y"}

n = int(input())
for i in range(n):
    text = input()

    for alpha in text:
        if alpha in dict1:
            print(dict1[alpha], end="")
        else:
            print(alpha, end="")
    print()