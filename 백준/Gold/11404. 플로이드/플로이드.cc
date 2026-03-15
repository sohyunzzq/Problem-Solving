#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

#define MAX_N 100
#define INF 1e9

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int graph[MAX_N + 1][MAX_N + 1];
	for (int i = 1; i <= MAX_N; i++)
		for (int j = 1; j <= MAX_N; j++)
			graph[i][j] = INF;

	for (int i = 1; i <= MAX_N; i++)
		graph[i][i] = 0;

	int n;
	cin >> n;

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;

		graph[a][b] = min(graph[a][b], w);
	}

	for (int k = 1; k <= n; k++)
		for (int a = 1; a <= n; a++)
			for (int b = 1; b <= n; b++)
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << (graph[i][j] == INF ? 0 : graph[i][j]) << " ";
		cout << endl;
	}
}