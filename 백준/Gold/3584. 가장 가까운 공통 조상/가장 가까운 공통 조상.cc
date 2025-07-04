/*
걍 LCA인 거 같은데
O(logN) 복습
*/

#include <iostream>
#include <vector>
using namespace std;

#define N_SZ 10'001

#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n;
int parent[N_SZ][20];
vector<int> depth;
vector<vector<int>> graph;

void Init() {
	for (int i = 0; i < N_SZ; i++) {
		for (int j = 0; j < 20; j++) {
			parent[i][j] = 0;
		}
	}
	depth.clear();
	graph.clear();
}

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
		depth[next] = depth[curr] + 1;
		DFS(next, curr);
	}
}

int main() {
	fastio;

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		Init();

		cin >> n;

		graph.resize(n + 1);
		depth.resize(n + 1);

		for (int i = 0; i < n - 1; i++) {
			int p, c;
			cin >> p >> c;

			graph[p].push_back(c);

			// 바로 위
			parent[c][0] = p;
		}

		for (int i = 1; i < 20; i++) {
			for (int x = 1; x <= n; x++) {
				parent[x][i] = parent[parent[x][i - 1]][i - 1];
			}
		}

		// depth 구하기
		// 부모가 없는 애가 루트
		int root_index;
		for (int i = 1; i <= n; i++)
			if (parent[i][0] == 0) {
				root_index = i;
				break;
			}

		DFS(root_index, -1);

		int f1, f2;
		cin >> f1 >> f2;

		cout << LCA(f1, f2) << endl;
	}
}