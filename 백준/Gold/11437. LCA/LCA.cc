#include <iostream>
#include <vector>
using namespace std;

#define N_SZ 50001
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n;
int m;
vector<vector<int>> graph;
int parent[N_SZ][20];
vector<int> depth;

int LCA(int f1, int f2) {
	if (depth[f1] < depth[f2])
		swap(f1, f2);

	for (int i = 19; i >= 0; i--) {
		if (depth[f1] - depth[f2] >= (1 << i))
			f1 = parent[f1][i];
	}

	if (f1 == f2)
		return f1;

	for (int i = 19; i >= 0; i--) {
		if (parent[f1][i] != parent[f2][i]) {
			f1 = parent[f1][i];
			f2 = parent[f2][i];
		}
	}

	return parent[f1][0];
}

void DFS(int curr, int prev) {
	for (int next : graph[curr]) {
		if (next == prev)
			continue;

		parent[next][0] = curr;
		depth[next] = depth[curr] + 1;
		DFS(next, curr);
	}
}

int main() {
	fastio;

	cin >> n;

	graph.resize(n + 1);
	depth.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(1, -1);

	for (int i = 1; i < 20; i++) {
		for (int x = 1; x <= n; x++) {
			parent[x][i] = parent[parent[x][i - 1]][i - 1];
		}
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		cout << LCA(a, b) << endl;
	}
}