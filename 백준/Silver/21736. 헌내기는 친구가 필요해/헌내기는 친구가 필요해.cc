#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<char>> arr;
vector<vector<int>> visited;
queue<pair<int, int>> q;
int cnt = 0;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y] && (arr[x][y] == 'O' || arr[x][y] == 'P');
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
				if (arr[nx][ny] == 'P')
					cnt++;
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
		visited[i].resize(m, 0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 'I') {
				visited[i][j] = 1;
				q.push({ i, j });
			}
		}
	}

	BFS();

	if (cnt)
		cout << cnt;
	else
		cout << "TT";
}