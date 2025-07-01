#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<char>> area;
vector<pair<int, int>> bomb;
vector<vector<int>> cnt;
vector<vector<int>> visited;
queue<pair<int, int>> q;

int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && area[x][y] == '.';
}

void GetCnt() {
	for (int i = 0; i < bomb.size(); i++) {
		pair<int, int> now = bomb[i];
		int x = now.first;
		int y = now.second;

		for (int dr = 0; dr < 8; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (CanGo(nx, ny)) {
				cnt[nx][ny]++;
			}
		}
	}
}

void BFS() {
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;

		for (int dr = 0; dr < 8; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (InRange(nx, ny) && !visited[nx][ny]) {
				if (cnt[nx][ny] == 0) {
					q.push({ nx, ny });
					visited[nx][ny] = 1;
				}
				else if (cnt[nx][ny] > 0) {
					visited[nx][ny] = 1;
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		
		area.clear();
		cnt.clear();
		visited.clear();
		bomb.clear();

		area.resize(n);
		cnt.resize(n);
		visited.resize(n);
		for (int i = 0; i < n; i++) {
			area[i].resize(n);
			cnt[i].resize(n, 0);
			visited[i].resize(n, 0);
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> area[i][j];

				if (area[i][j] == '*') {
					bomb.push_back({ i, j });
					cnt[i][j] = -1;
				}
			}

		GetCnt();

		int ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (cnt[i][j] == 0 && !visited[i][j]) {
					ans++;
					q.push({ i, j });
					visited[i][j] = 1;
					BFS();
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (cnt[i][j] > 0 && !visited[i][j])
					ans++;
			}
		}

		cout << "#" << tc << " " << ans << endl;
	}
}