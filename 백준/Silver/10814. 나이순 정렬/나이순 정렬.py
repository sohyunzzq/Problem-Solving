n = int(input())
member = []
for i in range(n):
    age, name = input().split()
    member.append([i, int(age), name])

member.sort(key = lambda x: (x[1], x[0]))

for i in range(n):
    print(member[i][1], member[i][2])