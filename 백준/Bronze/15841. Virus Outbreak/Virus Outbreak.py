ans = []
ans.append(0)
ans.append(1)

for i in range(2, 491):
    ans.append(ans[i-1] + ans[i-2])

while True:
    n = int(input())
    if n == -1:
        break

    print("Hour {}: {} cow(s) affected".format(n, ans[n]))