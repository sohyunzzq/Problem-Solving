#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, long long>>> graph;
vector<long long> w;

void DFS(int curr, int prev) {
	for (pair<int, long long> next : graph[curr]) {
		if (next.first == prev)
			continue;

		w[next.first] = next.second + w[curr];
		DFS(next.first, curr);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	graph.resize(n + 1);
	w.resize(n + 1, 0);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		long long c;

		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	DFS(1, -1);

	long long ans = 0;

	for (int i = 2; i <= n; i++) {
		ans = max(ans, w[i]);
	}

	cout << ans;
}