#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'

int n, m, k;
vector<vector<int>> area;
vector<vector<int>> visited;
queue<pair<int, int>> q;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y] && area[x][y] == 1;
}

void InitArr(vector<vector<int>>* arr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			(*arr)[i][j] = 0;
		}
	}
}

void BFS() {
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;

		for (int dr = 0; dr < 4; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (CanGo(nx, ny)) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> n >> m >> k;

		area.resize(n);
		visited.resize(n);
		for (int i = 0; i < n; i++) {
			area[i].resize(m, 0);
			visited[i].resize(m, 0);
		}

		InitArr(&area);
		InitArr(&visited);

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;

			area[x][y] = 1;
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (CanGo(i, j)) {
					ans++;
					visited[i][j] = 1;
					q.push({ i, j });
					BFS();
				}
			}
		}

		cout << ans << endl;
	}
}