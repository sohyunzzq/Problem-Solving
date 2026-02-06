#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'

int n, m;
vector<vector<int>> graph;
vector<int> visited;
queue<int> q;

void Init() {
	graph.clear();
	while (!q.empty())
		q.pop();
	visited.clear();
}

bool IsPossible() {
	for (int i = 1; i <= n; i++) {
		for (int nxt : graph[i]) {
			if (visited[i] == visited[nxt])
				return false;
		}
	}
	return true;
}

void Color() {
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int nxt : graph[now]) {
			if (visited[nxt] == -1) {
				visited[nxt] = (visited[now] + 1) % 2;
				q.push(nxt);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> m;

		Init();

		graph.resize(n + 1);
		visited.resize(n + 1, -1);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;

			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		for (int i = 1; i <= n; i++) {
			if (visited[i] == -1) {
				q.push(i);
				visited[i] = 1;
				Color();
			}
		}

		cout << (IsPossible() ? "possible" : "impossible") << endl;
	}
}