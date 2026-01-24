#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<char>> arr;
vector<vector<int>> visited;
bool alpha[26];
int ans = 1;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void DFS(int x, int y) {
	char c = arr[x][y];

	for (int dr = 0; dr < 4; dr++) {
		int nx = x + dx[dr];
		int ny = y + dy[dr];

		if (InRange(nx, ny)) {
			char nc = arr[nx][ny];

			if (!alpha[int(nc - 'A')]) {
				alpha[int(nc - 'A')] = true;
				visited[nx][ny] = visited[x][y] + 1;
				ans = max(ans, visited[nx][ny]);
				DFS(nx, ny);
				alpha[int(nc - 'A')] = false;
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
		}
	}

	visited[0][0] = 1;
	alpha[int(arr[0][0] - 'A')] = true;
	DFS(0, 0);

	cout << ans;
}