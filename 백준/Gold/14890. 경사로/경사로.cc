#include <iostream>
#include <vector>
using namespace std;

int n, l;
vector<vector<int>> area;
int ans;

int GetCnt_Row(int row) {
	int now_cnt = 1;
	int now_num = area[row][0];
	int last_cnt;
	int last_num;

	int col = 1;
	while (col < n) {
		// 계속 같은 숫자
		if (area[row][col] == now_num) {
			now_cnt++;
			col++;
		}
		// 연속이 끊김
		else {
			last_num = now_num;
			last_cnt = now_cnt;

			now_num = area[row][col];
			now_cnt = 1;
			// 숫자 2 이상 차이 나면 안 됨
			if (abs(last_num - now_num) != 1)
				return 0;

			// 높아지는 경우
			if (last_num < now_num) {
				if (last_cnt < l)
					return 0;
				col++;
			}
			// 낮아지는 경우
			else {
				int tmp = col + 1;
				while (tmp < col + l) {
					if (tmp >= n)
						return 0;
					if (area[row][tmp] != now_num) {
						return 0;
					}
					tmp++;
				}
				col += l;
				last_num = now_num;
				last_cnt = 0;
				now_cnt = 0;
			}
		}
	}
	return 1;
}


int GetCnt_Col(int col) {
	int now_cnt = 1;
	int now_num = area[0][col];
	int last_cnt;
	int last_num;

	int row = 1;
	while (row < n) {
		// 계속 같은 숫자
		if (area[row][col] == now_num) {
			now_cnt++;
			row++;
		}
		// 연속이 끊김
		else {
			last_num = now_num;
			last_cnt = now_cnt;

			now_num = area[row][col];
			now_cnt = 1;
			// 숫자 2 이상 차이 나면 안 됨
			if (abs(last_num - now_num) != 1)
				return 0;

			// 높아지는 경우
			if (last_num < now_num) {
				if (last_cnt < l)
					return 0;
				row++;
			}
			// 낮아지는 경우
			else {
				int tmp = row + 1;
				while (tmp < row + l) {
					if (tmp >= n)
						return 0;
					if (area[tmp][col] != now_num) {
						return 0;
					}
					tmp++;
				}
				row += l;
				last_num = now_num;
				last_cnt = 0;
				now_cnt = 0;
			}
		}
	}
	return 1;
}

void Solve() {
	// 행, 열 이미 전부 다 같은 숫자면 ans++
	// 가면서 숫자가 몇 개 연속되는지 세기
	// 숫자가 바뀌었는데,
	//	바뀔 때 숫자가 2 이상 차이 나면 return
	//	여태 나온 숫자 개수가 L개 미만일 때,
	//	여태 나온 숫자 < 지금 내 숫자 return
	for (int i = 0; i < n; i++)
		ans += GetCnt_Row(i);

	for (int i = 0; i < n; i++)
		ans += GetCnt_Col(i);
}

int main() {
	cin >> n >> l;
	area.resize(n);
	for (int i = 0; i < n; i++)
		area[i].resize(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> area[i][j];

	Solve();
	cout << ans;
}