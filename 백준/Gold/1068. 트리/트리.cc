#include <iostream>
#include <vector>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n;
vector<vector<int>> graph;
vector<int> parent;
vector<bool> leaf;
int node;

int cnt;

void DFS(int curr, int prev) {
	if (curr == node) {
		if (graph[prev].size() == 1)
			leaf[prev] = true;
		return;
	}
	if (graph[curr].size() == 0) {
		leaf[curr] = true;
		return;
	}

	for (int next : graph[curr]) {
		DFS(next, curr);
	}
}

int main() {
	fastio;
	cin >> n;

	parent.resize(n);
	leaf.resize(n);
	graph.resize(n);

	int root;

	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;

		parent[i] = p;
		if (p == -1) {
			root = i;
			continue;
		}
		graph[p].push_back(i);
	}

	cin >> node;
	if (node == root) {
		cout << 0;
	}
	else {
		DFS(root, -1);
		for (int i = 0; i < n; i++)
			if (leaf[i])
				cnt++;
		cout << cnt;
	}
}