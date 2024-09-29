n = int(input())
num = []

dict1 = {}
for i in range(n):
    tmp = int(input())
    num.append(tmp)
    if tmp not in dict1:
        dict1[tmp] = 1
    else:
        dict1[tmp] += 1

result = sum(num) / n

if result >= 0:
    if result * 10 % 10 >= 5:
        result = int(result) + 1
    else:
        result = int(result)
else:
    if result * (-10) % 10 >= 5:
        result = int(result) - 1
    else:
        result = int(result)

print(result)

print(sorted(num)[n // 2])

maxi = 0
ans = []
for key, value in dict1.items():
    maxi = max(maxi, value)

for key, value in dict1.items():
    if value == maxi:
        ans.append(key)

if len(ans) == 1:
    print(ans[0])
else:
    print(sorted(ans)[1])

print(max(num) - min(num))