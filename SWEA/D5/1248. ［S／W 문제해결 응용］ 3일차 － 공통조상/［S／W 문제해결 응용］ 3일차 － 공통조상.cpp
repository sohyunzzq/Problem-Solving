#include <iostream>
#include <vector>
using namespace std;

#define V_SZ 10001

vector<vector<int>> graph;
int depth[V_SZ];
int parents[V_SZ];
int sz[V_SZ];

int v, e;

int LCA(int f1, int f2) {
	// 깊이가 다르다면, 무조건 find2가 올라가도록
	if (depth[f1] < depth[f2]) {
		int temp = f1;
		f1 = f2;
		f2 = temp;
	}

	while (depth[f1] != depth[f2]) {
		f1 = parents[f1];
	}

	while (f1 != f2) {
		f1 = parents[f1];
		f2 = parents[f2];
	}

	return f1;
}

void DFS(int curr, int prev) {
	parents[curr] = prev;
	sz[curr] = 1;

	for (int next : graph[curr]) {
		if (next == prev)
			continue;

		depth[next] = depth[curr] + 1;
		DFS(next, curr);
		sz[curr] += sz[next];
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int find1, find2;
		cin >> v >> e >> find1 >> find2;

		graph.resize(v + 1);
		
		for (int i = 1; i <= v; i++)
			while (!graph[i].empty())
				graph[i].pop_back();

		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
		}

		DFS(1, -1);
		int res = LCA(find1, find2);
		cout << "#" << tc << " ";
		cout << res << " " << sz[res] << endl;
	}
}