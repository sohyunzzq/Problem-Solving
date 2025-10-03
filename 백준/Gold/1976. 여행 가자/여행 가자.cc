#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> visited;
queue<int> q;

void BFS() {
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 1; i <= n; i++) {
			if (graph[now][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	graph.resize(n + 1);
	visited.resize(n + 1, 0);
	for (int i = 0; i <= n; i++) {
		graph[i].resize(n + 1);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> graph[i][j];

	int st;
	cin >> st;

	q.push(st);
	visited[st] = 1;
	BFS();

	vector<int> cities(m);
	for (int i = 1; i < m; i++) {
		cin >> cities[i];
	}

	bool flag = true;
	for (int i = 1; i < m; i++)
		if (visited[cities[i]] == 0)
			flag = false;

	cout << (flag ? "YES" : "NO");
}