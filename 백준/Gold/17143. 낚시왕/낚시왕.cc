#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

struct Shark {
	int x, y;
	int speed;
	int dr;
	int sz;
};

int r, c, m;
vector<struct Shark> sharks;
vector<vector<int>> area;
int fisher = -1;
int ans = 0;

bool InRange(int x, int y) {
	return 0 <= x && x < r && 0 <= y && y < c;
}

int DistToWall(struct Shark tmp) {
	switch (tmp.dr) {

		// 위를 향함, 벽까지 x칸
	case 1: {
		return tmp.x;
	}

		  // 아래를 향함, 벽까지 (r-1-x)칸
	case 2: {
		return r - 1 - tmp.x;
	}

		  // 오른쪽을 향함, 벽까지 (c-1-y)칸
	case 3: {
		return c - 1 - tmp.y;
	}

		  // 왼쪽을 향함, 벽까지 y칸
	default: {
		return tmp.y;
	}
	}
}

int ChangeDr(int dr) {
	if (dr == 1)
		return 2;
	if (dr == 2)
		return 1;
	if (dr == 3)
		return 4;
	return 3;
}

void CatchShark() {
	struct Shark dummy = { r, c, 0, 0, 0 };
	struct Shark* target = &dummy;
	for (int i = 0; i < m; i++) {
		// 이미 죽은 상어
		if (sharks[i].x == -1 && sharks[i].y == -1) {
			continue;
		}

		// 피셔랑 같은 열이고, 행이 가장 작은 상어
		if (sharks[i].y == fisher && sharks[i].x < (*target).x)
			target = &sharks[i];
	}

	// 잡을 수 있는 게 없음
	if ((*target).x == r && (*target).y == c)
		return;

	// 죽이기
	area[(*target).x][(*target).y]--;
	(*target).x = (*target).y = -1;
	ans += (*target).sz;
}

void MoveShark() {
	for (int i = 0; i < m; i++) {
		// 이미 죽은 상어
		if (sharks[i].x == -1 && sharks[i].y == -1) {
			continue;
		}

		int dx[] = { 0, -1, 1, 0, 0 };
		int dy[] = { 0, 0, 0, 1, -1 };

		// 이동해야 하는 거리
		int move = sharks[i].speed;
		area[sharks[i].x][sharks[i].y]--;

		// 현재 방향으로 가면 벽까지 얼마나 걸리는지
		int dist = DistToWall(sharks[i]);

		// 벽에 닿기 전에 이동 끝남
		if (move <= dist) {
			sharks[i].x += dx[sharks[i].dr] * sharks[i].speed;
			sharks[i].y += dy[sharks[i].dr] * sharks[i].speed;
		}
		else {
			// 일단 벽까지 가기
			sharks[i].x += dx[sharks[i].dr] * dist;
			sharks[i].y += dy[sharks[i].dr] * dist;
			move -= dist;

			// 벽까지 갔는데 더 가야 함
			if (move) {
				sharks[i].dr = ChangeDr(sharks[i].dr);

				// 위아래
				if (sharks[i].dr == 1 || sharks[i].dr == 2) {
					move %= 2 * (r - 1);

					while (move--) {
						int nx = sharks[i].x + dx[sharks[i].dr];
						if (!InRange(nx, sharks[i].y)) {
							sharks[i].dr = ChangeDr(sharks[i].dr);
							nx = sharks[i].x + dx[sharks[i].dr];
						}
						sharks[i].x = nx;
					}
				}
				else {
					move %= 2 * (c - 1);

					while (move--) {
						int ny = sharks[i].y + dy[sharks[i].dr];
						if (!InRange(sharks[i].x, ny)) {
							sharks[i].dr = ChangeDr(sharks[i].dr);
							ny = sharks[i].y + dy[sharks[i].dr];
						}
						sharks[i].y = ny;
					}
				}
			}
		}

		area[sharks[i].x][sharks[i].y]++;
	}
}

void EatShark() {
	vector<struct Shark*> tmp;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (area[i][j] >= 2) {
				tmp.clear();

				for (int k = 0; k < m; k++) {
					if (sharks[k].x == -1 && sharks[k].y == -1)
						continue;

					if (sharks[k].x == i && sharks[k].y == j)
						tmp.push_back(&sharks[k]);
				}

				// 정렬 후 가장 큰 애 빼고 다 죽이기
				// 정렬 잘 안 되길래 그냥 일일이 구함...
				struct Shark* biggest = tmp[0];
				for (int p = 1; p < tmp.size(); p++) {
					if (tmp[p]->sz > biggest->sz)
						biggest = tmp[p];
				}

				for (int p = 0; p < tmp.size(); p++) {
					if (tmp[p] == biggest)
						continue;

					area[(*tmp[p]).x][(*tmp[p]).y]--;
					(*tmp[p]).x = (*tmp[p]).y = -1;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> m;
	area.resize(r);
	for (int i = 0; i < r; i++) {
		area[i].resize(c, 0);
	}

	for (int i = 0; i < m; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;

		a--; b--;
		struct Shark shark = { a,b,c,d,e };
		sharks.push_back(shark);
		area[a][b] = 1;
	}

	if (m == 0)
		cout << 0;
	else {
		while (fisher != c - 1) {
			// 1. 피셔 오른쪽으로 한 칸 이동
			fisher++;

			// 2. 상어 잡기
			// 잡히면 좌표 -1, -1로 변경
			CatchShark();

			// 3. 상어 이동
			MoveShark();

			// 3-1. 상어끼리 잡아먹음
			EatShark();
		}
		cout << ans;
	}
}