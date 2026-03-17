#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> graph;
	graph.resize(n);
	for (int i = 0; i < n; i++)
		graph[i].resize(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];

	for (int k = 0; k < n; k++)
		for (int a = 0; a < n; a++)
			for (int b = 0; b < n; b++)
				if (graph[a][k] && graph[k][b])
					graph[a][b] = graph[a][k] + graph[k][b];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << (graph[i][j] ? 1 : 0) << " ";
		cout << endl;
	}
}