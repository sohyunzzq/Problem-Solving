from collections import deque

n, k = map(int, input().split())

result = []
q = deque(item for item in range(1, n + 1))

while q:
    for i in range(k - 1):
        q.append(q.popleft())
    result.append(q.popleft())

print("<", end = "")
for i in range(n-1):
    print("{}, ".format(result[i]), end = "")
print("{}>".format(result[-1]))