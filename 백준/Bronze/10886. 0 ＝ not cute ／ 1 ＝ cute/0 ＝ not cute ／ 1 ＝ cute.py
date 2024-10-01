n = int(input())
lst = []
yes, no = 0, 0
for i in range(n):
    if int(input()) == 1:
        yes += 1
    else:
        no += 1

if yes > no:
    print("Junhee is cute!")
else:
    print("Junhee is not cute!")