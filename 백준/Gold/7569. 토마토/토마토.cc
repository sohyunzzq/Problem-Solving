/*
[BFS]

상하좌우앞뒤
n, m, h이 최대 100이니까 벡터 쓰지 말고 걍 배열 만들어두기

arr[z][x][y]
행, 열은 걍 dx, dy 써주고
z는 z-1 z+1로 해당 칸만 검사해주면 됨
*/

#include <iostream>
#include <queue>
using namespace std;

#define SZ 100
#define endl '\n'

struct Point {
	int z, x, y;
};

// 가로 세로 높이
int m, n, h;
int arr[SZ][SZ][SZ];
int visited[SZ][SZ][SZ];
queue<struct Point> q;
int ans = 1;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool InRange(int z, int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && 0 <= z && z < h;
}

bool CanGo(int z, int x, int y) {
	return InRange(z, x, y) && !visited[z][x][y] && arr[z][x][y] == 0;
}

bool IsCompleted() {
	for (int z = 0; z < h; z++) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (visited[z][x][y] == 0 && arr[z][x][y] == 0)
					return false;
			}
		}
	}
	return true;
}

void BFS() {
	while (!q.empty()) {
		struct Point now = q.front(); q.pop();
		int x = now.x;
		int y = now.y;
		int z = now.z;

		for (int dr = 0; dr < 4; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (CanGo(z, nx, ny)) {
				visited[z][nx][ny] = visited[z][x][y] + 1;
				ans = max(ans, visited[z][nx][ny]);
				q.push({ z, nx, ny });
			}
		}

		if (CanGo(z - 1, x, y)) {
			visited[z - 1][x][y] = visited[z][x][y] + 1;
			ans = max(ans, visited[z - 1][x][y]);
			q.push({ z - 1, x, y });
		}
		if (CanGo(z + 1, x, y)) {
			visited[z + 1][x][y] = visited[z][x][y] + 1;
			ans = max(ans, visited[z + 1][x][y]);
			q.push({ z + 1, x, y });
		}
	}
}

int main() {
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[i][j][k];
			}
		}
	}

	for (int z = 0; z < h; z++) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (arr[z][x][y] == 1) {
					visited[z][x][y] = 1;
					q.push({ z, x, y });
				}
			}
		}
	}

	BFS();
	cout << (IsCompleted() ? ans - 1 : -1);
}