def dfs(vertex, count):
    global maxi
    maxi = max(maxi, count)

    for v in graph[vertex]:
        if not visited[v]:
            visited[v] = 1
            dfs(v, count + 1)
    visited[vertex] = 0

maxi = 0
t = int(input())
for case in range(1, t + 1):
    n, m = map(int, input().split())

    graph = []
    for i in range(n + 1):
        graph.append([])

    for i in range(m):
        x, y = map(int, input().split())
        graph[x].append(y)
        graph[y].append(x)

    maxi = 0
    for v in range(1, n + 1):
        visited = [0] * (n + 1)
        visited[v] = 1

        dfs(v, 1)

    print("#{} {}".format(case, maxi))