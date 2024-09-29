dict1 = {}

string = input()
for item in string:
    if item.upper() not in dict1:
        dict1[item.upper()] = 1
    else:
        dict1[item.upper()] += 1

candi = []
for i in dict1:
    candi.append(dict1[i])
maxi = max(candi)

ans = []
for key, value in dict1.items():
    if value == maxi:
        ans.append(key)

if len(ans) == 1:
    print(ans[0].upper())
else:
    print("?")