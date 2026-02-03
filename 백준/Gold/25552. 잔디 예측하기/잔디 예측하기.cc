#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, d;
vector<vector<char>> arr1;
vector<vector<char>> arr2;
vector<vector<int>> visited;
queue<pair<int, int>> q;

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y] && arr2[x][y] == 'O';
}

bool IsCorrect() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr1[i][j] != arr2[i][j])
				return false;
		}
	}
	return true;
}

void BFS() {
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;

		for (int nx = x - d; nx <= x + d; nx++) {
			for (int ny = y - d; ny <= y + d; ny++) {
				if (CanGo(nx, ny) && abs(x - nx) + abs(y - ny) <= d) {
					q.push({ nx, ny });
					visited[nx][ny] = 1;
					arr1[nx][ny] = 'O';
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	arr1.resize(n);
	arr2.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		arr1[i].resize(m);
		arr2[i].resize(m);
		visited[i].resize(m, 0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr1[i][j];
			if (arr1[i][j] == 'O') {
				q.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}

	cin >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr2[i][j];
		}
	}

	BFS();

	cout << (IsCorrect() ? "YES" : "NO");
}