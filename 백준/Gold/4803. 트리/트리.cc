/*
그래프 탐색을 하고
(정점 수-1) == (간선 수) 이면 트리
*/

#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n, m;
int tc;
vector<int> visited;
vector<int> IsTree;
vector<vector<int>> graph;
int now;

void Init() {
	graph.clear();
	visited.clear();
	IsTree.clear();
}

void DFS(int curr, int prev) {
	for (int next : graph[curr]) {
		if (next == prev)
			continue;

		if (visited[next]) {
			IsTree[now] = 0;
			return;
		}

		visited[next] = 1;
		DFS(next, curr);
	}
}

void Output(int cnt) {
	cout << "Case " << tc << ": ";
	switch (cnt) {
	case 0:
		cout << "No trees.";
		break;
	case 1:
		cout << "There is one tree.";
		break;
	default:
		cout << "A forest of " << cnt << " trees.";
		break;
	}
	cout << endl;
}

int main() {
	fastio;

	while (1) {
		cin >> n >> m;
		if (!n && !m)
			break;
		tc++;

		Init();
		graph.resize(n + 1);
		IsTree.resize(n + 1, 1);
		visited.resize(n + 1, 0);

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		int cnt = 0;

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				now = i;
				visited[i] = 1;
				DFS(i, 0);

				if (IsTree[i])
					cnt++;
			}
		}

		Output(cnt);
	}
}