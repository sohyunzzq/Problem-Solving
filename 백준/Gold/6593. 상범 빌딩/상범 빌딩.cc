/*
동서남북상하
토마토랑 같은? 문제?

상하좌우는 그냥 dx dy 써서 알아내면 되고
인접한 층만 따로 체크해주면 됨
*/

#include <iostream>
#include <queue>
using namespace std;

#define SZ 30
#define endl '\n'

struct Point {
	int x, y, z;
};

int l, r, c;
char building[SZ][SZ][SZ];
int visited[SZ][SZ][SZ];
queue<struct Point> q;
int ans;

int dy[] = { -1, 0, 1, 0 };
int dz[] = { 0, 1, 0, -1 };

void InitVisited() {
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			for (int k = 0; k < SZ; k++) {
				visited[i][j][k] = 0;
			}
		}
	}
}

bool InRange(int x, int y, int z) {
	return 0 <= x && x < l && 0 <= y && y < r && 0 <= z && z < c;
}

bool CanGo(int x, int y, int z) {
	return InRange(x, y, z) && !visited[x][y][z] && building[x][y][z] != '#';
}

void BFS() {
	while (!q.empty()) {
		struct Point now = q.front(); q.pop();
		int x = now.x;
		int y = now.y;
		int z = now.z;

		// 탈출
		if (building[x][y][z] == 'E') {
			ans = visited[x][y][z];
			while (!q.empty())
				q.pop();
			return;
		}

		// 같은 층
		for (int dr = 0; dr < 4; dr++) {
			int ny = y + dy[dr];
			int nz = z + dz[dr];

			if (CanGo(x, ny, nz)) {
				q.push({ x, ny, nz });
				visited[x][ny][nz] = visited[x][y][z] + 1;
			}
		}

		// 인접한 층
		if (CanGo(x + 1, y, z)) {
			q.push({ x + 1, y, z });
			visited[x + 1][y][z] = visited[x][y][z] + 1;
		}
		if (CanGo(x - 1, y, z)) {
			q.push({ x - 1, y, z });
			visited[x - 1][y][z] = visited[x][y][z] + 1;
		}
	}
}

int main() {
	while (1) {
		cin >> l >> r >> c;
		if (!l && !r && !c)
			break;

		InitVisited();
		ans = -1;
		for (int x = 0; x < l; x++) {
			for (int y = 0; y < r; y++) {
				for (int z = 0; z < c; z++) {
					cin >> building[x][y][z];

					if (building[x][y][z] == 'S') {
						building[x][y][z] = '.';
						q.push({ x, y, z });
						visited[x][y][z] = 1;
					}
				}
			}
		}

		BFS();

		if (ans != -1) {
			cout << "Escaped in " << ans - 1 << " minute(s).";
		}
		else {
			cout << "Trapped!";
		}
		cout << endl;
	}
}