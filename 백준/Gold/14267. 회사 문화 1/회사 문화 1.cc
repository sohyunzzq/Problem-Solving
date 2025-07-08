#include <iostream>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n, m;
vector<int> parent;
vector<long long> weights;
vector<vector<int>> graph;

void DFS(int curr, int prev) {
	for (int next : graph[curr]) {
		if (next == prev)
			continue;
		
		weights[next] += weights[curr];
		DFS(next, curr);
	}
}

int main() {
	fastio;

	cin >> n >> m;
	weights.resize(n + 1);
	parent.resize(n + 1);
	graph.resize(n + 1);

	int a;
	cin >> a;

	for (int i = 2; i <= n; i++) {
		cin >> parent[i];
		graph[parent[i]].push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int num, w;
		cin >> num >> w;

		weights[num] += w;
	}

	DFS(1, -1);

	for (int i = 1; i <= n; i++)
		cout << weights[i] << " ";
}