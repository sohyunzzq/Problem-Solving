#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n, m;
vector<vector<pair<int, int>>> graph;
int st, en;
int ans;

void DFS(int curr, int prev, int sum) {
	for (pair<int, int> next : graph[curr]) {
		if (next.first == prev)
			continue;

		if (next.first == en) {
			ans = sum + next.second;
			return;
		}

		DFS(next.first, curr, sum + next.second);
	}
}

int main() {
	fastio;

	cin >> n >> m;
	graph.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;

		graph[a].push_back({ b, w });
		graph[b].push_back({ a, w });
	}

	for (int i = 0; i < m; i++) {
		ans = 0;
		cin >> st >> en;
		DFS(st, 0, 0);
		cout << ans << endl;
	}
}