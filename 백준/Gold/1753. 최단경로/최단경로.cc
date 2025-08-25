#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'

#define V_SZ 20'001

struct Cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

int v, e;
int st;
vector<vector<pair<int, int>>> graph;
priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
int dist[V_SZ];

void Dijkstra() {
	while (!pq.empty()) {
		pair<int, int> now = pq.top(); pq.pop();

		// 예전 정보면 버려
		if (now.second > dist[now.first])
			continue;

		// now의 이웃들 거리 갱신
		for (pair<int, int> nxt : graph[now.first]) {
			if (dist[nxt.first] > dist[now.first] + nxt.second) {
				dist[nxt.first] = dist[now.first] + nxt.second;
				pq.push({nxt.first, dist[nxt.first]});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> v >> e >> st;
	graph.resize(v + 1);

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
	}

	for (int i = 1; i <= v; i++)
		dist[i] = 1e9;

	dist[st] = 0;
	pq.push({ st, -0 });

	Dijkstra();

	for (int i = 1; i <= v; i++) {
		if (dist[i] == 1e9)
			cout << "INF";
		else
			cout << dist[i];
		cout << endl;
	}
}