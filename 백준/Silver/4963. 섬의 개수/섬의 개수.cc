#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'

int n, m;
vector<vector<int>> arr;
vector<vector<int>> visited;
queue<pair<int, int>> q;
int cnt;

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void Init() {
	arr.clear();
	visited.clear();
	while (!q.empty())
		q.pop();
	cnt = 0;
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && arr[x][y] && !visited[x][y];
}

void BFS() {
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;

		for (int dr = 0; dr < 8; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (CanGo(nx, ny)) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	while (1) {
		cin >> m >> n;

		if (!n && !m)
			break;

		Init();
		arr.resize(n);
		visited.resize(n);
		for (int i = 0; i < n; i++) {
			arr[i].resize(m);
			visited[i].resize(m, 0);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] && !visited[i][j]) {
					q.push({ i, j });
					visited[i][j] = 1;
					BFS();
					cnt++;
				}
			}
		}

		cout << cnt << endl;
	}
}