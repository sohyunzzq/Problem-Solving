bowl = input()
cm = 10

p = bowl[0]
for i in range(1, len(bowl)):
    if bowl[i] == p:
        cm += 5
    else:
        cm += 10
        p = bowl[i]

print(cm)