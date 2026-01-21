#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

vector<vector<int>> graph;
vector<int> visited;
vector<int> cnt;
int idx = 0;

void DFS(int curr) {
	for (int nxt : graph[curr]) {
		if (!visited[nxt]) {
			visited[nxt] = 1;
			idx++;
			cnt[nxt] = idx;
			DFS(nxt);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;

	graph.resize(n + 1);
	visited.resize(n + 1, 0);
	cnt.resize(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	cnt[r] = 1;
	idx = 1;
	visited[r] = 1;
	DFS(r);

	for (int i = 1; i <= n; i++)
		cout << cnt[i] << endl;
}