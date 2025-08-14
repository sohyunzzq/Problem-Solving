#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 0;
	while (1) {
		tc++;

		int n;
		cin >> n;

		if (n == 0)
			break;

		vector<vector<long long>> graph;
		graph.resize(n);
		for (int i = 0; i < n; i++)
			graph[i].resize(3);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++)
				cin >> graph[i][j];

		graph[0][2] += graph[0][1];
		graph[1][0] += graph[0][1];
		long long min_val = min(graph[0][1], graph[1][0]);
		graph[1][1] += min(min_val, graph[0][2]);
		min_val = min(graph[0][1], graph[0][2]);
		graph[1][2] += min(min_val, graph[1][1]);

		for (int row = 2; row < n; row++) {
			// 0번 열
			graph[row][0] += min(graph[row - 1][0], graph[row - 1][1]);

			// 1번 열
			long long min_val = min(graph[row - 1][0], graph[row - 1][1]);
			min_val = min(min_val, graph[row - 1][2]);
			graph[row][1] += min(min_val, graph[row][0]);

			// 2번 열
			min_val = min(graph[row - 1][1], graph[row - 1][2]);
			graph[row][2] += min(min_val, graph[row][1]);
		}

		cout << tc << ". " << graph[n - 1][1] << endl;
	}
}