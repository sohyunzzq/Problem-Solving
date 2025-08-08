#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> depth;
queue<int> q;

void BFS() {
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int next : graph[now]) {
			if (visited[next])
				continue;
			visited[next] = 1;
			q.push(next);
			depth[next] = depth[now] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;

	depth.resize(n + 1, 0);
	visited.resize(n + 1, 0);
	graph.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	q.push(1);
	visited[1] = 1;
	BFS();

	int cnt = 0;
	for (int i = 2; i <= n; i++)
		if (0 < depth[i] && depth[i] <= 2)
			cnt++;
	cout << cnt;
}