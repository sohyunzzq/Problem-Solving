/*
[백트래킹 & BFS]
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N_SZ 50
#define M_SZ 10
#define endl '\n'

int n, m;
vector<vector<int>> area;
vector<vector<int>> temp;
vector<vector<int>> visited;
vector<pair<int, int>> virus;
vector<pair<int, int>> choose;
bool path[M_SZ + 1];
queue<pair<int, int>> q;
int ans = N_SZ * 2;
int max_time;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void InitArr(vector<vector<int>>(*arr)) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			(*arr)[i][j] = 0;
		}
	}
}

void CopyArr(vector<vector<int>> *dst, vector<vector<int>> *src) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			(*dst)[i][j] = (*src)[i][j];
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y] && temp[x][y] == 0;
}

void BFS() {
	max_time = 0;
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;

		for (int dr = 0; dr < 4; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (CanGo(nx, ny)) {
				q.push({ nx, ny });
				visited[nx][ny] = visited[x][y] + 1;
				max_time = max(max_time, visited[nx][ny]);
			}
		}
	}
}

bool Check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (temp[i][j] == 0 && visited[i][j] == 0)
				return false;
		}
	}
	return true;
}

void Simulation() {
	// 안 고른 바이러스는 0으로 만들어줘야 함
	InitArr(&visited);
	CopyArr(&temp, &area);

	for (int i = 0; i < virus.size(); i++) {
		if (path[i])
			continue;

		int x = virus[i].first;
		int y = virus[i].second;

		temp[x][y] = 0;
	}

	for (int i = 0; i < virus.size(); i++) {
		if (path[i]) {
			q.push(virus[i]);
			visited[virus[i].first][virus[i].second] = 1;
		}
	}
	BFS();

	// 모든 빈 칸에 퍼뜨렸다면 갱신
	if (Check())
		ans = min(max_time, ans);
}

void func(int index) {
	if (choose.size() == m) {
		Simulation();
		return;
	}

	for (int i = index; i < virus.size(); i++) {
		choose.push_back(virus[i]);
		path[i] = true;
		func(i + 1);
		choose.pop_back();
		path[i] = false;
	}
}

int main() {
	cin >> n >> m;
	area.resize(n);
	temp.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		area[i].resize(n);
		temp[i].resize(n);
		visited[i].resize(n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> area[i][j];

			if (area[i][j] == 2)
				virus.push_back({ i, j });
		}
	}

	func(0);

	if (ans == N_SZ * 2)
		cout << -1;
	else
		cout << max(0, ans - 1);
}