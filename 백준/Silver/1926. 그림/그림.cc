#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> area;
vector<vector<int>> visited;
queue<pair<int, int>> q;
int cnt = 0;
int maxi = 0;
int sz = 0;

int InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int CanGo(int x, int y) {
	return InRange(x, y) && area[x][y] == 1 && !visited[x][y];
}

void BFS() {
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, 1, 0, -1 };

	sz = 1;

	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;

		for (int dr = 0; dr < 4; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (CanGo(nx, ny)) {
				sz++;
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	area.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		area[i].resize(m);
		visited[i].resize(m, 0);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> area[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (area[i][j] == 1 && !visited[i][j]) {
				q.push({ i, j });
				visited[i][j] = 1;
				BFS();

				maxi = max(maxi, sz);
				cnt++;
			}
		}

	cout << cnt << endl << maxi;
}