#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'

int n, m;
vector<vector<int>> arr;
vector<vector<int>> visited;
queue<pair<int, int>> q;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && visited[x][y] == 0 && arr[x][y] == 1;
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

	pair<int, int> st;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 2)
				st = { i, j };
		}
	}

	q.push(st);
	BFS();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0)
				cout << -1;
			else
				cout << visited[i][j];
			cout << " ";
		}
		cout << endl;
	}
}