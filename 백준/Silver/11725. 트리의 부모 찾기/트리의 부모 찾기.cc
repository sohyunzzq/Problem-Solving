#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

vector<vector<int>> graph;
vector<int> parent;

void DFS(int curr, int prev) {
	for (int next : graph[curr]) {
		if (next == prev)
			continue;

		parent[next] = curr;
		DFS(next, curr);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	graph.resize(n + 1);
	parent.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(1, -1);

	for (int i = 2; i <= n; i++)
		cout << parent[i] << endl;
}