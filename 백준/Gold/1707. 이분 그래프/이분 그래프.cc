#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'

int v, e;
vector<vector<int>> graph;
vector<int> visited;
vector<int> team;
queue<int> q;
bool flag = true;

void Init() {
	while (!q.empty())
		q.pop();
	graph.clear();
	visited.clear();
	flag = true;
}

void BFS() {
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int nxt : graph[now]) {
			if (visited[nxt]) {
				if (team[nxt] == team[now]) {
					flag = false;
					while (!q.empty())
						q.pop();
					return;
				}
			}
			else {
				visited[nxt] = 1;
				team[nxt] = (team[now] + 1) % 3;
				q.push(nxt);
			}
		}
	}
}

void IsBiGraph() {
	for (int i = 1; i <= v; i++) {
		for (int nxt : graph[i]) {
			if (team[i] == team[nxt]) {
				flag = false;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> v >> e;

		Init();
		graph.resize(v+1);
		team.resize(v+1, 0);
		visited.resize(v + 1, 0);

		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i = 1; i <= v; i++) {
			if (!visited[i]) {
				visited[i] = 1;
				q.push(i);
				team[i] = 1;
				BFS();
			}
		}

		if (flag)
			IsBiGraph();

		cout << (flag ? "YES" : "NO") << endl;
	}
}