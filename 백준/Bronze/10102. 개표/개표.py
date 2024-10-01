n = int(input())
string = input()

a, b = 0, 0
for item in string:
    if item == "A":
        a += 1
    else:
        b += 1

if a > b:
    print("A")
elif a < b:
    print("B")
else:
    print("Tie")