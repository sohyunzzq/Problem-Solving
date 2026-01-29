#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'

vector<vector<int>> graph;
vector<int> visited;
queue<int> q;

void BFS() {
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int nxt : graph[now]) {
			if (visited[nxt] == -1) {
				visited[nxt] = visited[now] + 1;
				q.push(nxt);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, k, x;
	cin >> n >> m >> k >> x;

	graph.resize(n + 1);
	visited.resize(n + 1, -1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
	}

	visited[x] = 0;
	q.push(x);
	BFS();

	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == k) {
			cout << i << endl;
			flag = true;
		}
	}
	if (!flag)
		cout << -1;
}