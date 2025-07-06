#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n;
vector<vector<int>> area;
vector<pair<int, int>> cores;
int max_cnt;
int min_len;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void Init() {
	area.clear();
	cores.clear();
	max_cnt = 0;
	min_len = 0;
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && area[x][y] == 0;
}

int GetLen(int ori_x, int ori_y, int dr) {
	int x = ori_x;
	int y = ori_y;

	while (1) {
		int nx = x + dx[dr];
		int ny = y + dy[dr];

		// 벽에 부딪힘 -> 현재 방향 가능
		if (!InRange(nx, ny))
			break;

		// 앞에 장애물
		if (area[nx][ny] != 0)
			return -1;

		x = nx;
		y = ny;
	}

	// 이 방향으로 갈 수 있으니 다 표시
	int len = 0;
	x = ori_x;
	y = ori_y;

	while (1) {
		int nx = x + dx[dr];
		int ny = y + dy[dr];

		if (!CanGo(nx, ny))
			return len;

		area[nx][ny] = 2;
		len++;
		x = nx;
		y = ny;
	}
}

void recover(int x, int y, int dr) {
	while (1) {
		int nx = x + dx[dr];
		int ny = y + dy[dr];

		if (!InRange(nx, ny))
			return;

		area[nx][ny] = 0;
		x = nx;
		y = ny;
	}
}

void func(int idx, int sum, int cnt) {
	if (cnt > max_cnt) {
		max_cnt = cnt;
		min_len = sum;
	}
	else if (cnt == max_cnt)
		min_len = min(min_len, sum);

	// 끝~
	if (idx >= cores.size())
		return;

	int x = cores[idx].first;
	int y = cores[idx].second;

	// 각 방향으로 뻗는 거 가능한지 체크
	for (int dr = 0; dr < 4; dr++) {
		int len = GetLen(x, y, dr);
		
		// 이 방향 안 됨
		if (len == -1)
			continue;

		func(idx + 1, sum + len, cnt + 1);
		// 다 체크하고 돌아온 후 다시 되돌리기
		recover(x, y, dr);
	}

	// 지금 코어는 연결 못해
	func(idx + 1, sum, cnt);
}

int main() {
	fastio;

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Init();

		cin >> n;
		area.resize(n);

		for (int i = 0; i < n; i++) {
			area[i].resize(n);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> area[i][j];

				if (area[i][j] == 1) {
					if (i != 0 && i != n - 1 && j != 0 && j != n - 1)
						cores.push_back({ i, j });
				}
			}
		}

		func(0, 0, 0);
		cout << "#" << tc << " " << min_len << endl;
	}
}