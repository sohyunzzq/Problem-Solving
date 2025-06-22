/*
[백트래킹]
*/

#include <iostream>
using namespace std;

#define N_SZ 15

int n;
int path[N_SZ];
int ans;

bool Check(int row) {
	for (int i = 0; i < row; i++) {
		if (path[i] == path[row] ||
			abs(path[row] - path[i]) == row - i) {
			return false;
		}
	}
	return true;
}

void func(int row) {
	if (row == n) {
		ans++;
		return;
	}

	for (int col = 0; col < n; col++) {
		// 현재 row의 col 위치에 일단 놓기
		path[row] = col;

		if (Check(row))
			func(row + 1);
	}
}

int main() {
	cin >> n;

	func(0);
	cout << ans;
}