#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<char>> arr;
queue<pair<int, int>> q;
vector<vector<int>> visited;
int ans = 0;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void Init() {
	while (!q.empty())
		q.pop();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = -1;
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && visited[x][y] == -1 && arr[x][y] == 'L';
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
				visited[nx][ny] = visited[x][y] + 1;
				ans = max(ans, visited[nx][ny]);
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	arr.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		arr[i].resize(m);
		visited[i].resize(m);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L') {
				Init();

				visited[i][j] = 0;
				q.push({ i, j });
				BFS();
			}
		}
	}

	cout << ans;
}