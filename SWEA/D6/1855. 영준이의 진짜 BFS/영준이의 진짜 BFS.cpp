/*
depth를 일단 다 구해 (루트 ~ 내 거리)
(depth[curr] - depth[LCA]) + (depth[next] - depth[LCA])

BFS 순서를 다 기억해야 하는데 어케 하지?
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N_SZ 100'001

vector<vector<int>> graph;
int parent[N_SZ][20];
vector<int> depth;
queue<int> q;
vector<int> bfs;

void BFS() {
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int next : graph[now]) {
			q.push(next);
			bfs.push_back(next);
			depth[next] = depth[now] + 1;
		}
	}
}

int LCA(int f1, int f2) {
	// 다르다면 f1이 더 깊게 (f1이 올라가야 함)
	if (depth[f1] < depth[f2])
		swap(f1, f2);

	// 큰 점프부터 시도
	for (int i = 19; i >= 0; i--) {
		if (depth[f1] - depth[f2] >= (1 << i)) {
			f1 = parent[f1][i];
		}
	}

	// 점프한 게 LCA
	if (f1 == f2)
		return f1;

	// 이제 depth[f1] == depth[f2]
	// 공통 조상 나오기 딱 직전에 멈추기
	for (int i = 19; i >= 0; i--) {
		if (parent[f1][i] != parent[f2][i]) {
			f1 = parent[f1][i];
			f2 = parent[f2][i];
		}
	}

	return parent[f1][0];
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;

		graph.clear();
		depth.clear();
		bfs.clear();

		graph.resize(n + 1);
		depth.resize(n + 1, 0);

		for (int i = 2; i <= n; i++) {
			int num;
			cin >> num;

			graph[num].push_back(i);

			// 한 칸 위 조상은 미리 구해야 함
			parent[i][0] = num;
		}

		// BFS 순서 & depth 구하기
		q.push(1);
		bfs.push_back(1);
		BFS();

		// parent 배열 채우기
		for (int x = 1; x <= n; x++) {
			for (int i = 1; i < 20; i++) {
				parent[x][i] = parent[parent[x][i - 1]][i - 1];
			}
		}

		// 순서대로 LCA 계산 후 더해주기
		long long ans = 0;
		
		for (int i = 0; i < n-1; i++) {
			int curr = bfs[i];
			int next = bfs[i + 1];

			int lca = LCA(curr, next);

			ans += (depth[curr] - depth[lca]) + (depth[next] - depth[lca]);
		}

		cout << "#" << tc << " " << ans << endl;
	}
}