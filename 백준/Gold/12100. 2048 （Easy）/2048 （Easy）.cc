/*
[시뮬레이션, 단순 구현, 백트래킹]

각 방향마다 미는 함수를 각각 만들기
끝에서부터 채우기
합쳐지는 거 잘 생각해서 비울 데 비워야 함

우선 그 방향으로 다 밀고
그 다음에 합쳐지는 거 생각하기

최대 5번 이동
*/

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> ORIGIN;
vector<vector<int>> TMP;
vector<vector<int>> PULLED;
vector<vector<int>> MERGED;
int directions[5];
int ans = 0;

void Copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			TMP[i][j] = ORIGIN[i][j];
		}
	}
}

void InitPulled() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			PULLED[i][j] = 0;
		}
	}
}

void InitMerged() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			MERGED[i][j] = 0;
		}
	}
}

void GoUp() {
	// 일단 밀기
	// 민 결과를 PULLED에 저장
	// 위로 올리려면, col로 돌리면서 위에서 아래로 보면 됨
	InitPulled();
	InitMerged();
	for (int col = 0; col < n; col++) {
		int index = 0;
		for (int row = 0; row < n; row++) {
			if (TMP[row][col]) {
				PULLED[index++][col] = TMP[row][col];
			}
		}
	}

	// 합쳐질 수 있는 거 보기
	// 위에서부터 보면서 합치기
	for (int col = 0; col < n; col++) {
		int index = 0;
		for (int row = 0; row < n; row++) {
			if (row < n - 1 && PULLED[row][col] == PULLED[row + 1][col]) {
				MERGED[index++][col] = PULLED[row][col] * 2;
				row++;
			}
			else {
				MERGED[index++][col] = PULLED[row][col];
			}
		}
	}

	// 다음 걸 진행하기 위해 TMP에 다시 MERGED 복사해주기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			TMP[i][j] = MERGED[i][j];
		}
	}
}

void GoRight() {
	// 일단 밀기
	// 민 결과를 PULLED에 저장
	InitPulled();
	InitMerged();
	for (int row = 0; row < n; row++) {
		int index = n-1;
		for (int col = n-1; col >=0; col--) {
			if (TMP[row][col]) {
				PULLED[row][index--] = TMP[row][col];
			}
		}
	}

	// 합쳐질 수 있는 거 보기
	for (int row = 0; row < n; row++) {
		int index = n-1;
		for (int col = n-1; col >= 0; col--) {
			if (col > 0 && PULLED[row][col] == PULLED[row][col -1]) {
				MERGED[row][index--] = PULLED[row][col] * 2;
				col--;
			}
			else {
				MERGED[row][index--] = PULLED[row][col];
			}
		}
	}

	// 다음 걸 진행하기 위해 TMP에 다시 MERGED 복사해주기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			TMP[i][j] = MERGED[i][j];
		}
	}
}

void GoDown() {
	// 일단 밀기
	// 민 결과를 PULLED에 저장
	InitPulled();
	InitMerged();
	for (int col = 0; col < n; col++) {
		int index = n - 1;
		for (int row = n - 1; row >= 0; row--) {
			if (TMP[row][col]) {
				PULLED[index--][col] = TMP[row][col];
			}
		}
	}

	// 합쳐질 수 있는 거 보기
	for (int col = 0; col < n; col++) {
		int index = n - 1;
		for (int row = n - 1; row >= 0; row--) {
			if (row > 0 && PULLED[row][col] == PULLED[row - 1][col]) {
				MERGED[index--][col] = PULLED[row][col] * 2;
				row--;
			}
			else {
				MERGED[index--][col] = PULLED[row][col];
			}
		}
	}

	// 다음 걸 진행하기 위해 TMP에 다시 MERGED 복사해주기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			TMP[i][j] = MERGED[i][j];
		}
	}
}

void GoLeft() {
	// 일단 밀기
	// 민 결과를 PULLED에 저장
	InitPulled();
	InitMerged();
	for (int row = 0; row < n; row++) {
		int index = 0;
		for (int col = 0; col < n; col++) {
			if (TMP[row][col]) {
				PULLED[row][index++] = TMP[row][col];
			}
		}
	}

	// 합쳐질 수 있는 거 보기
	for (int row = 0; row < n; row++) {
		int index = 0;
		for (int col = 0; col < n; col++) {
			if (col < n - 1 && PULLED[row][col] == PULLED[row][col + 1]) {
				MERGED[row][index++] = PULLED[row][col] * 2;
				col++;
			}
			else {
				MERGED[row][index++] = PULLED[row][col];
			}
		}
	}

	// 다음 걸 진행하기 위해 TMP에 다시 MERGED 복사해주기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			TMP[i][j] = MERGED[i][j];
		}
	}
}

void MOVE() {
	// 이 directions에서 쓸 임시 배열 TMP 업데이트
	Copy();

	for (int i = 0; i < 5; i++) {
		int cmd = directions[i];

		switch (cmd)
		{
		case 0: {
			GoUp();
			break;
		}
		case 1: {
			GoRight();
			break;
		}
		case 2: {
			GoDown();
			break;
		}
		case 3: {
			GoLeft();
			break;
		}
		}
	}
}

void GetMax() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans = max(ans, TMP[i][j]);
}

void func(int curr) {
	if (curr == 5) {
		// 방향 결정 완료
		// 결정된 방향대로 움직이기
		MOVE();
		GetMax();
		return;
	}

	for (int dr = 0; dr < 4; dr++) {
		directions[curr] = dr;
		func(curr + 1);
	}
}

int main() {
	cin >> n;
	ORIGIN.resize(n);
	PULLED.resize(n);
	MERGED.resize(n);
	TMP.resize(n);
	for (int i = 0; i < n; i++) {
		ORIGIN[i].resize(n);
		PULLED[i].resize(n);
		MERGED[i].resize(n);
		TMP[i].resize(n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ORIGIN[i][j];
		}
	}

	func(0);
	cout << ans;
}