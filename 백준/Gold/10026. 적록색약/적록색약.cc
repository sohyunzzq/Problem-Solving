/*
[BFS]

적록색약이 아닌 사람이 봤을 때 돌릴 BFS
적록색약인 사람이 봤을 때 돌릴 BFS

하나의 BFS를 같이 쓸 수는 없나?
걍 적록색약 아닌 거 먼저 돌리고, 원본 R을 전부 G로 바꿔
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<char>> area;
vector<vector<int>> visited;
queue<pair<int, int>> q;
int ans[2];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y];
}

void BFS() {
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;

		for (int dr = 0; dr < 4; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (CanGo(nx, ny) && area[x][y] == area[nx][ny]) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
			}
		}
	}
}

int main() {
	cin >> n;
	area.resize(n);
	visited.resize(n);

	for (int i = 0; i < n; i++) {
		area[i].resize(n);
		visited[i].resize(n, 0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> area[i][j];
		}
	}

	// 색약 아님
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				q.push({ i, j });
				visited[i][j] = 1;
				ans[0]++;
				BFS();
			}
		}
	}

	// 색약 -> 색 바꾸고, visited 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (area[i][j] == 'R')
				area[i][j] = 'G';
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				q.push({ i, j });
				visited[i][j] = 1;
				ans[1]++;
				BFS();
			}
		}
	}

	cout << ans[0] << " " << ans[1];
}