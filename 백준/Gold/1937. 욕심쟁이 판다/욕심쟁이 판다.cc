#include <iostream>
#include <vector>
using namespace std;

int ans = 0;

int n;
vector<vector<int>> arr;
vector<vector<int>> visited;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y];
}

void DFS(int x, int y) {
	visited[x][y] = 0;
	
	for (int dr = 0; dr < 4; dr++) {
		int nx = x + dx[dr];
		int ny = y + dy[dr];

		if (InRange(nx, ny) && arr[nx][ny] > arr[x][y]) {
			if (visited[nx][ny] == -1) {
				DFS(nx, ny);
			}

			visited[x][y] = max(visited[x][y], visited[nx][ny] + 1);
			ans = max(ans, visited[x][y]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	arr.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		arr[i].resize(n);
		visited[i].resize(n, -1);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// arr[i][j]에서 출발

			// 진작에 구해뒀으면 패스
			if (visited[i][j] == -1) {
				DFS(i, j);
			}
		}
	}

	cout << ans + 1;
}