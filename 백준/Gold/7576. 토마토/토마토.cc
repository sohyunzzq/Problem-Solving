/*
[BFS]

1인 데를 찾고 BFS 돌리면서 0인 데를 1로 만들기
1인 게 여러 개일 수 있음 -> 동시에 뻗어나감
한 번 찾을 때 다 넣어두고, 다 검사한 후 BFS는 한 번만 호출
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int ans = 0;
vector<vector<int>> area;
vector<vector<int>> dist;
vector<vector<int>> visited;
queue<pair<int, int>> q;

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && area[x][y] == 0 && !visited[x][y];
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
				area[nx][ny] = 1;
				visited[nx][ny] = 1;
				q.push({ nx, ny });
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main() {
	cin >> m >> n;
	area.resize(n);
	visited.resize(n);
	dist.resize(n);
	for (int i = 0; i < n; i++) {
		area[i].resize(m);
		visited[i].resize(m, 0);
		dist[i].resize(m, 0);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> area[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (area[i][j] == 1 && !visited[i][j]) {
				visited[i][j] = 1;
				dist[i][j] = 1;
				q.push({ i, j });
			}
		}
	}

	BFS();

	bool IsCompleted = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (area[i][j] == 0) {
				IsCompleted = false;
				break;
			}
			ans = max(dist[i][j], ans);
		}
	}

	cout << (IsCompleted ? ans - 1 : -1);
}