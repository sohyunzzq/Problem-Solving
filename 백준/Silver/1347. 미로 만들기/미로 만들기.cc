#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	string str;
	cin >> n >> str;

	// 남쪽을 보고 서 있음
	int dr = 2;

	// 위부터 시계 방향
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	// 초기 위치
	int x = 0, y = 0;

	// 어디까지 뻗는지
	int min_x = 0, max_x = 0;
	int min_y = 0, max_y = 0;

	for (int i = 0; i < n; i++) {
		char cmd = str[i];

		if (cmd == 'F') {
			x += dx[dr];
			y += dy[dr];
			min_x = min(min_x, x);
			max_x = max(max_x, x);
			min_y = min(min_y, y);
			max_y = max(max_y, y);
		}
		else if (cmd == 'L')
			dr = (dr + 3) % 4;
		else if (cmd == 'R')
			dr = (dr + 1) % 4;
	}

	// 격자
	int width = max_y - min_y + 1;
	int height = max_x - min_x + 1;
	vector<string> area(height);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			area[i].push_back('#');

	// OFFSET
	int OFFSET_x = 0, OFFSET_y = 0;
	OFFSET_x = min_x > 0 ? 0 : -min_x;
	OFFSET_y = min_y > 0 ? 0 : -min_y;
	
	// 시뮬레이션 시작
	// x, y 좌표에 OFFSET 더해주기
	x = OFFSET_x, y = OFFSET_y;
	dr = 2;
	area[x][y] = '.';

	for (int i = 0; i < n; i++) {
		char cmd = str[i];

		if (cmd == 'F') {
			x += dx[dr];
			y += dy[dr];
			area[x][y] = '.';
		}
		else if (cmd == 'L')
			dr = (dr + 3) % 4;
		else if (cmd == 'R')
			dr = (dr + 1) % 4;
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			cout << area[i][j];
		cout << endl;
	}
}