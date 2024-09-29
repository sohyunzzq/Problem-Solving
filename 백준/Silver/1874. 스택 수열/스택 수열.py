n = int(input())
ans = []
for i in range(n):
    ans.append(int(input()))

num = 1
tmp = []
lst = [] #마지막에 ans랑 비교
cmd = []

for i in range(n):
    if i == 0 or ans[i] > lst[-1]:
        while num <= ans[i]:
            tmp.append(num)
            cmd.append("+")
            num += 1
        lst.append(tmp.pop())
        cmd.append("-")
    else:
        lst.append(tmp.pop())
        cmd.append("-")

while tmp:
    lst.append(tmp.pop())
    cmd.append("-")

if ans == lst:
    for item in cmd:
        print(item)
else:
    print("NO")