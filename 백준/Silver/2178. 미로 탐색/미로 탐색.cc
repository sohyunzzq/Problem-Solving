/*
[BFS]

(0, 0) -> (N-1, M-1) 최단 거리
char로 받아서 1일 때만 쭉쭉 가기
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<char>> area;
vector<vector<int>> visited;
vector<vector<int>> dist;
queue<pair<int, int>> q;

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && area[x][y] == '1' && !visited[x][y];
}

void BFS() {
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, 1, 0, -1 };
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;

		for (int dr = 0; dr < 4; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (CanGo(nx, ny)) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	area.resize(n);
	visited.resize(n);
	dist.resize(n);
	for (int i = 0; i < n; i++) {
		area[i].resize(m);
		dist[i].resize(m, 0);
		visited[i].resize(m, 0);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> area[i][j];

	q.push({ 0, 0 });
	visited[0][0] = 1;
	dist[0][0] = 1;
	BFS();

	cout << dist[n - 1][m - 1];
}