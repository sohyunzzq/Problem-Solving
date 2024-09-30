from collections import deque

n, m, vertex = map(int, input().split())
graph = []
for i in range(n + 1):
    graph.append([0] * (n + 1))

for i in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1

def dfs(vertex):
    for i in range(1, n + 1):
        if graph[vertex][i] and not visited[i]:
            print(i, end = " ")
            visited[i] = 1
            dfs(i)

def bfs():
    while q:
        vertex = q.popleft()
        for i in range(1, n + 1):
            if graph[vertex][i] and not visited[i]:
                print(i, end = " ")
                visited[i] = 1
                q.append(i)

visited = [0] * (n+1)
visited[vertex] = 1
print(vertex, end = " ")
dfs(vertex)
print()

visited = [0] * (n+1)
visited[vertex] = 1
q = deque()
q.append(vertex)
print(vertex, end = " ")
bfs()