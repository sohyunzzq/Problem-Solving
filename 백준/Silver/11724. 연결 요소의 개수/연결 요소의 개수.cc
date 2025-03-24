#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'

vector<vector<int>> graph;
vector<int> visited;
int cnt;
queue<int> q;

void BFS() {
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];

			if (!visited[next]) {
				visited[next] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	
	visited.resize(n + 1);
	graph.resize(n + 1);
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			q.push(i);
			cnt++;
			BFS();
		}
	}

	cout << cnt;
}