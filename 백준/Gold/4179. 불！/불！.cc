/*
[BFS]

불이 어디로 퍼질 수 있는지는 고정
지훈이 갈 수 있는 경우의 수는 많음

F 먼저 다 퍼뜨리고, 몇 초에 퍼지는지 다 써두기
J BFS 돌리면서 (F 시간) <= (지금 시간) 이면 못 가
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point {
	int x, y;
};

int r, c;
vector<vector<char>> area;
vector<vector<int>> fire_time;
vector<vector<int>> walk_time;
vector<vector<int>> visited;
queue<struct Point> F;
queue<struct Point> J;
int ans = -1;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool InRange(int x, int y) {
	return 0 <= x && x < r && 0 <= y && y < c;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y] && area[x][y] != '#';
}

void InitArr(vector<vector<int>>* visited) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			(*visited)[i][j] = 0;
		}
	}
}

void BFS_F() {
	while (!F.empty()) {
		struct Point now = F.front(); F.pop();
		int x = now.x;
		int y = now.y;

		for (int dr = 0; dr < 4; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (CanGo(nx, ny)) {
				F.push({ nx, ny });
				visited[nx][ny] = 1;
				fire_time[nx][ny] = fire_time[x][y] + 1;
			}
		}
	}
}

void BFS_J() {
	while (!J.empty()) {
		struct Point now = J.front(); J.pop();
		int x = now.x;
		int y = now.y;

		for (int dr = 0; dr < 4; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			// 탈출
			if (!InRange(nx, ny)) {
				ans = walk_time[x][y] + 1;
				return;
			}
			if (CanGo(nx, ny) &&
				(walk_time[x][y] + 1 < fire_time[nx][ny] - 1 || fire_time[nx][ny] == 0)) {
				J.push({ nx, ny });
				visited[nx][ny] = 1;
				walk_time[nx][ny] = walk_time[x][y] + 1;
			}
		}
	}
}

int main() {
	cin >> r >> c;
	area.resize(r);
	fire_time.resize(r);
	walk_time.resize(r);
	visited.resize(r);
	for (int i = 0; i < r; i++) {
		area[i].resize(c);
		fire_time[i].resize(c, 0);
		walk_time[i].resize(c, 0);
		visited[i].resize(c, 0);
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> area[i][j];
		}
	}

	// F 퍼뜨리기
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (area[i][j] == 'F') {
				F.push({ i, j });
				fire_time[i][j] = 1;
				visited[i][j] = 1;
			}
		}
	}
	BFS_F();

	InitArr(&visited);

	// J 움직이기
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (area[i][j] == 'J') {
				J.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}
	BFS_J();

	if (ans == -1)
		cout << "IMPOSSIBLE";
	else
		cout << ans;
}