n = int(input())
set1 = {0}

for i in range(n):
    set1.add(input())

set1.remove(0)

lst = list(set1)
lst.sort(key = lambda x: (len(x), x))

for item in lst:
    print(item)