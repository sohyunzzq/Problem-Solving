#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cmp {
	// second가 더 큰 쪽이 위로 가도록
	// max heap
	bool operator()(const pair<int, long long>& a, const pair<int, long long>& b) {
		return a.second < b.second;
	}
};

int n, m;
vector<vector<pair<int, long long>>> graph;
int st, en;
priority_queue<pair<int, long long>, vector<pair<int, long long>>, Cmp> pq;
vector<long long> cost;

void Dijkstra() {
	while (!pq.empty()) {
		pair<int, long long> tmp = pq.top(); pq.pop();

		int now_node = tmp.first;
		long long now_cost = tmp.second;

		if (now_cost < cost[now_node])
			continue;

		for (pair<int, long long> nxt : graph[now_node]) {
			int nxt_node = nxt.first;
			long long nxt_cost = min(nxt.second, cost[now_node]);

			if (cost[nxt_node] == 1e12 || cost[nxt_node] < nxt_cost) {
				cost[nxt_node] = nxt_cost;
				pq.push({ nxt_node, cost[nxt_node] });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	graph.resize(n + 1);
	cost.resize(n + 1, 1e12);

	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;

		// a->b 무게 c
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	cin >> st >> en;

	pq.push({ st, 1e12 });

	Dijkstra();

	cout << (cost[en] == 1e12 ? 0 : cost[en]);
}