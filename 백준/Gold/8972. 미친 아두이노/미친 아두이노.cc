#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int r, c;
vector<string> board;
string cmds;
vector<struct Arduino> ardus;
int ans = 0;

int dx[10] = { 0, 1, 1, 1, 0, 0, 0, -1, -1, -1 };
int dy[10] = { 0, -1, 0, 1, -1, 0, 1, -1, 0, 1 };

struct Arduino {
	bool status;
	int num;
	int x, y;
};

void FindPos(char target, int* x, int* y) {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (board[i][j] == target) {
				*x = i;
				*y = j;
				return;
			}
}

bool IsEnd(int x, int y) {
	for (int i = 0; i < ardus.size(); i++)
		if (ardus[i].status && ardus[i].x == x && ardus[i].y == y)
			return true;
	return false;
}

bool CanMove(int dr, int* x, int* y) {
	int nx = (*x) + dx[dr];
	int ny = (*y) + dy[dr];

	// 이동한 곳에서 아두이노 마주침
	if (IsEnd(nx, ny))
		return false;

	*x = nx;
	*y = ny;

	return true;
}

int GetDr(int x, int y, int ax, int ay) {
	int min_dis = INT_MAX;
	int dr = 5;
	for (int i = 1; i <= 9; i++) {
		int dis = abs(x - (ax + dx[i])) + abs(y - (ay + dy[i]));
		if (dis < min_dis) {
			min_dis = dis;
			dr = i;
		}
	}
	return dr;
}

int ArduMove(struct Arduino* ardu, int dr, int x, int y) {
	int nx = (*ardu).x + dx[dr];
	int ny = (*ardu).y + dy[dr];

	// 나랑 겹치는가?
	if (nx == x && ny == y)
		return false;

	(*ardu).x = nx;
	(*ardu).y = ny;

	return true;
}

void KillArdu() {
	// 아두이노 위치 표시하는 격자 temp
	vector<vector<int>> temp(r, vector<int>(c, 0));
	for (int i = 0; i < ardus.size(); i++)
		if (ardus[i].status)
			temp[ardus[i].x][ardus[i].y]++;

	// 내 자리에 2개 이상이면 죽기
	for (int i = 0; i < ardus.size(); i++)
		if (ardus[i].status && temp[ardus[i].x][ardus[i].y] > 1)
			ardus[i].status = false;
}

int main() {
	cin >> r >> c;
	board.resize(r);
	for (int i = 0; i < r; i++)
		cin >> board[i];
	cin >> cmds;

	// 아두이노 정보
	int num = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (board[i][j] == 'R')
				ardus.push_back({ true, num++, i, j });

	// 현재 내 위치
	int x, y;
	FindPos('I', &x, &y);

	// 패배 여부 플래그
	int lose = 0;

	// 게임 시작
	for (int i = 0; i < cmds.size(); i++) {
		if (lose)
			break;

		ans++;
		int cmd = cmds[i] - '0';

		// 나 움직였을 때 아두이노랑 겹치면 게임 종료
		if (!CanMove(cmd, &x, &y)) {
			lose = 1;
			break;
		}

		// 아두이노 움직이기
		for (int j = 0; j < ardus.size(); j++) {
			int dr = GetDr(x, y, ardus[j].x, ardus[j].y);
			if (ardus[j].status && !ArduMove(&ardus[j], dr, x, y)) {
				lose = 1;
				break;
			}
		}

		// 아두이노 겹치는 건 다 죽이기
		KillArdu();

		// 보드 업데이트
		// 보드 초기화
		for (int j = 0; j < r; j++)
			for (int k = 0; k < c; k++)
				board[j][k] = '.';

		// 내 위치
		board[x][y] = 'I';

		// 아두이노 위치
		for (int j = 0; j < ardus.size(); j++)
			if (ardus[j].status)
				board[ardus[j].x][ardus[j].y] = 'R';
	}

	if (lose)
		cout << "kraj " << ans;
	else {
		for (int i = 0; i < r; i++)
			cout << board[i] << '\n';
	}
}