/*
[DFS/BFS]

BFS 돌리면서 큐에 넣을 때마다 마운트 증가시키기
정답 벡터에 넣고 마지막에 소트
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define endl '\n'

queue<pair<int, int>> q;
int n;
vector<string> area;
vector<vector<int>> visited;
int cnt;
vector<int> ans;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && area[x][y] == '1' && !visited[x][y];
}

void BFS() {
	while (!q.empty()) {
		pair<int, int> v = q.front();
		q.pop();

		int x = v.first;
		int y = v.second;

		for (int dr = 0; dr < 4; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (CanGo(nx, ny)) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
				cnt++;
			}
		}
	}
}

int main() {
	cin >> n;
	area.resize(n);
	visited.resize(n);

	for (int i = 0; i < n; i++) {
		area[i].resize(n);
		visited[i].resize(n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> area[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (CanGo(i, j)) {
				cnt = 1;
				q.push({ i, j });
				visited[i][j] = true;
				BFS();
				ans.push_back(cnt);
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}