/*
[DFS/BFS]
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'

vector<vector<int>> graph;
queue<int> q;
vector<int> visited;
int cnt;

void BFS() {
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];

			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				cnt++;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	graph.resize(n + 1);
	visited.resize(n + 1);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	q.push(1);
	visited[1] = true;
	BFS();

	cout << cnt;
}