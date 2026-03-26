#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> graph;
vector<int> visited;
vector<vector<int>> dp;

void DFS(int curr) {
	visited[curr] = 1;
	dp[curr][0] = 0;
	dp[curr][1] = 1;

	for (int nxt : graph[curr]) {
		if (visited[nxt])
			continue;
		DFS(nxt);

		dp[curr][0] += dp[nxt][1];
		dp[curr][1] += min(dp[nxt][0], dp[nxt][1]);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	graph.resize(n + 1);
	visited.resize(n + 1, 0);
	dp.resize(n + 1);
	for (int i = 1; i <= n; i++)
		dp[i].resize(2);
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	visited[1] = 1;
	DFS(1);

	cout << min(dp[1][0], dp[1][1]);
}