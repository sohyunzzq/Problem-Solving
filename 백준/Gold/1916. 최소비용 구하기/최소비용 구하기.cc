#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define SZ 1'001

struct Cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

int n, m;
vector<vector<pair<int, int>>> graph;
int dist[SZ];
priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;

void Dijkstra() {
	while (!pq.empty()) {
		pair<int, int> now = pq.top(); pq.pop();

		if (dist[now.first] < now.second)
			continue;

		for (pair<int, int> nxt : graph[now.first]) {
			if (dist[nxt.first] > dist[now.first] + nxt.second) {
				dist[nxt.first] = dist[now.first] + nxt.second;
				pq.push({ nxt.first, dist[nxt.first] });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	graph.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
	}

	for (int i = 1; i <= n; i++)
		dist[i] = 1e9;

	int st, en;
	cin >> st >> en;

	dist[st] = 0;
	pq.push({ st, 0 });

	Dijkstra();

	cout << dist[en];
}