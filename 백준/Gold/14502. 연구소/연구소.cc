#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> area;
vector<vector<int>> temp;
vector<vector<int>> visited;
vector<pair<int, int>> zero;
vector<pair<int, int>> choose;
int ans;
queue<pair<int, int>> q;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y] && temp[x][y] == 0;
}

void CopyArr(vector<vector<int>>* dst, vector<vector<int>>* src) {
	for (int i = 0; i < n; i++)  {
		for (int j = 0; j < m; j++) {
			(*dst)[i][j] = (*src)[i][j];
		}
	}
}

void InitArr(vector<vector<int>>* arr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			(*arr)[i][j] = 0;
		}
	}
}

int GetCnt() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}

void BFS() {
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;
		temp[x][y] = 2;

		for (int dr = 0; dr < 4; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (CanGo(nx, ny)) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
			}
		}
	}
}

void Simulation() {
	CopyArr(&temp, &area);
	InitArr(&visited);

	// 벽 설치
	for (int i = 0; i < 3; i++) {
		int x = choose[i].first;
		int y = choose[i].second;

		temp[x][y] = 1;
	}

	// 바이러스 퍼뜨리기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 2) {
				q.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}
	BFS();

	ans = max(ans, GetCnt());
}

void func(int index) {
	if (choose.size() == 3) {
		Simulation();
		return;
	}

	for (int i = index; i < zero.size(); i++) {
		choose.push_back(zero[i]);
		func(i + 1);
		choose.pop_back();
	}
}

int main() {
	cin >> n >> m;
	area.resize(n);
	temp.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		area[i].resize(m);
		temp[i].resize(m);
		visited[i].resize(m);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> area[i][j];

			if (area[i][j] == 0)
				zero.push_back({ i, j });
		}
	}

	func(0);
	cout << ans;
}