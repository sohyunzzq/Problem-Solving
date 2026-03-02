#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> parent;

struct Edge {
	int a, b, w;
};

struct Cmp {
	bool operator()(const struct Edge& left, const struct Edge& right) {
		return left.w < right.w;
	}
};

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	int X = Find(x);
	int Y = Find(y);

	parent[X] = Y;
}

int main() {
	int v, e;
	cin >> v >> e;

	parent.resize(v + 1);
	for (int i = 1; i <= v; i++)
		parent[i] = i;

	vector<Edge> graph;
	for (int i = 0; i < e; i++) {
		int a, b, w;
		cin >> a >> b >> w;

		graph.push_back({ a, b, w });
	}

	sort(graph.begin(), graph.end(), Cmp());

	long long ans = 0;

	for (int i = 0; i < e; i++) {
		int x = graph[i].a;
		int y = graph[i].b;

		if (Find(x) != Find(y)) {
			Union(x, y);
			ans += graph[i].w;
		}
	}

	cout << ans;
}