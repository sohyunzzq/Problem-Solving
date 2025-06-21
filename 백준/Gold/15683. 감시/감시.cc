/*
모든 경우의 수를 다 해보기?
CCTV 최대 8개니까 걍 다 돌려보면 될 거 같긴 한데

CCTV 번호마다 가능한 방향을 저장해둬야 할 듯?
백트로?

이거 안 터지나 근데
CCTV가 8개고, 다 1번이면 4^8 = 2^16, 근데 격자 작아서 터지진 않을 듯

1은 4개
2는 2개
3은 4개
4는 4개
5는 0개

1은 위부터 회전
2는 LR, UD로 구분
3, 4는 그림을 기준으로 회전
*/

#include <iostream>
#include <vector>
using namespace std;

#define UD 0
#define LR 1
#define endl '\n'

int n, m;
vector<vector<int>> area;
vector<vector<int>> temp;
int CCTV_CNT;
vector<pair<int, int>> CCTV;
vector<int> choose;
int ans = 8 * 8;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void CopyArr(vector<vector<int>> *dst, vector<vector<int>> *src) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			(*dst)[i][j] = (*src)[i][j];
		}
	}
}

void Draw(int x, int y, int dr) {
	while (1) {
		int nx = x + dx[dr];
		int ny = y + dy[dr];

		// 격자 벗어나거나, 벽
		if (!InRange(nx, ny) || temp[nx][ny] == 6)
			return;

		if (temp[nx][ny] <= 0)
			temp[nx][ny] = -1;
		x = nx;
		y = ny;
	}
}

void Simulation() {
	CopyArr(&temp, &area);

	for (int i = 0; i < CCTV_CNT; i++) {
		int x = CCTV[i].first;
		int y = CCTV[i].second;

		if (temp[x][y] == 1) {
			int dr = choose[i];
			Draw(x, y, dr);
		}
		else if (temp[x][y] == 2) {
			// dr이 0이면 UD, 1이면 LR
			if (choose[i] == 0) {
				for (int dr = 0; dr < 4; dr += 2) {
					Draw(x, y, dr);
				}
			}
			else {
				for (int dr = 1; dr < 4; dr += 2) {
					Draw(x, y, dr);
				}
			}
		}
		else if (temp[x][y] == 3) {
			int dr = choose[i];
			for (int i = 0; i < 2; i++) {
				Draw(x, y, (dr + i) % 4);
			}
		}
		else if (temp[x][y] == 4) {
			int dr = choose[i];
			for (int i = 0; i < 4; i++) {
				if (dr == i)
					continue;
				Draw(x, y, i);
			}
		}
		else {
			for (int dr = 0; dr < 4; dr++) {
				Draw(x, y, dr);
			}
		}
	}

	int zero = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				zero++;
			}
		}
	}

	ans = min(ans, zero);
}

void func(int curr) {
	if (curr == CCTV_CNT) {
		Simulation();
		return;
	}

	int x = CCTV[curr].first;
	int y = CCTV[curr].second;

	// 의미 없음
	if (area[x][y] == 5) {
		choose.push_back(0);
		func(curr + 1);
		choose.pop_back();
	}
	// LR or UD
	else if (area[x][y] == 2) {
		for (int i = 0; i < 2; i++) {
			choose.push_back(i);
			func(curr + 1);
			choose.pop_back();
		}
	}
	// 그림 기준 회전
	else {
		for (int i = 0; i < 4; i++) {
			choose.push_back(i);
			func(curr + 1);
			choose.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;
	area.resize(n);
	temp.resize(n);
	for (int i = 0; i < n; i++) {
		area[i].resize(m);
		temp[i].resize(m);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> area[i][j];

			// CCTV 저장
			if (1 <= area[i][j] && area[i][j] <= 5) {
				CCTV.push_back({ i, j });
				CCTV_CNT++;
			}
		}
	}

	func(0);
	cout << ans;
}