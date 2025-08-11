#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

vector<vector<int>> graph;
vector<int> apple;
vector<int> depth;

void DFS(int curr, int prev) {
	for (int next : graph[curr]) {
		if (next == prev)
			continue;

		depth[next] = depth[curr] + 1;
		DFS(next, curr);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k;
	cin >> n >> k;

	graph.resize(n);
	apple.resize(n);
	depth.resize(n);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
		cin >> apple[i];

	DFS(0, -1);

	int ans = 0;
	for (int i = 0; i < n; i++)
		if (depth[i] <= k)
			ans += apple[i];

	cout << ans;
}