/*
[시뮬레이션, 단순 구현]

7개밖에 안 되니 그냥 각 col마다 계산해서 최솟값 갱신하기

입력 받은 배열 ORIGIN을 직접적으로 수정하지 말고
한 번 떨굴 때마다, 공 없앨 때마다 따로 배열 만들어줘야 함
한 번 떨군 배열을 전역으로 선언하고,
그걸 함수로 옮겨서 공 없앨 때 또 따로 만들어서 계산하기

세로 그룹, 가로 그룹 각각 동시에 해야 하니
바로바로 0으로 만들면 영향 끼쳐서 안 된다는 거 기억하기
*/

#include <iostream>
#include <algorithm>
using namespace std;

int ORIGIN[7][7];
int DROPPED[7][7];
int BOMB[7][7];
int TMP[7][7];
int ball;
int flag;
int ans = 50;

void CopyBOMB() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			BOMB[i][j] = DROPPED[i][j];
		}
	}
}

void InitTMP() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			TMP[i][j] = 0;
		}
	}
}

void GaroGroup() {
	// DROPPED 배열의 가로그룹 찾기
	for (int row = 0; row < 7; row++) {
		for (int col = 0; col < 7; col++) {
			if (!DROPPED[row][col])
				continue;
			int start = col;
			int end = start;
			while (DROPPED[row][end] && end <= 6) {
				end++;
			}

			// 그룹 원소 개수 len개
			// 그룹 원소 == len 이면 터뜨리기
			int len = end - start;
			for (int i = 0; i < len; i++) {
				if (DROPPED[row][col + i] == len) {
					BOMB[row][col + i] = 0;
					flag = 1;
				}
			}
			col = end - 1;
		}
	}
}

void SeroGroup() {
	// DROPPED 배열의 세로그룹 찾기
	for (int col = 0; col < 7; col++) {
		for (int row = 0; row < 7; row++) {
			if (!DROPPED[row][col])
				continue;
			int start = row;
			int end = start;
			while (DROPPED[end][col] && end <= 6) {
				end++;
			}

			// 그룹 원소 개수 len개
			// 그룹 원소 == len 이면 터뜨리기
			int len = end - start;
			for (int i = 0; i < len; i++) {
				if (DROPPED[row + i][col] == len) {
					BOMB[row + i][col] = 0;
					flag = 1;
				}
			}
			row = end - 1;
		}
	}
}

void DropOne(int here) {
	// here행에 공 떨구기
	for (int col = 0; col < 7; col++) {
		// here행
		if (col == here) {
			for (int row = 6; row >= 0; row--) {
				if (ORIGIN[row][col] == 0) {
					DROPPED[row][col] = ball;
					break;
				}
				else {
					DROPPED[row][col] = ORIGIN[row][col];
				}
			}
		}
		else {
			for (int row = 0; row < 7; row++) {
				DROPPED[row][col] = ORIGIN[row][col];
			}
		}
	}
}

void DropAll() {
	InitTMP();
	for (int col = 0; col < 7; col++) {
		int index = 6;
		for (int row = 6; row >= 0; row--) {
			if (BOMB[row][col]) {
				TMP[index--][col] = BOMB[row][col];
			}
		}
	}

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			DROPPED[i][j] = TMP[i][j];
		}
	}
}

int CountBall() {
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (DROPPED[i][j]) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cin >> ORIGIN[i][j];
		}
	}
	cin >> ball;

	for (int col = 0; col < 7; col++) {
		flag = 1;
		DropOne(col);
		while (flag) {
			CopyBOMB();
			flag = 0;
			GaroGroup();
			SeroGroup();
			DropAll();
		}
		ans = min(ans, CountBall());
	}
	cout << ans;
}