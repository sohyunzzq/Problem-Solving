#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> arr;
int ans = 0;
// 가로 세로 대각선
int dx[] = { 0, 1, 1 };
int dy[] = { 1, 0, 1 };
// 시작 가로
int dr = 0;

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && arr[x][y] == 0;
}

bool Straight(int x, int y, int nxt_dr) {
	return CanGo(x + dx[nxt_dr], y + dy[nxt_dr]);
}

bool Diagonal(int x, int y) {
	for (int i = 0; i < 3; i++) {
		if (!CanGo(x + dx[i], y + dy[i]))
			return false;
	}
	return true;
}

void DFS(int x, int y) {
	if (x == n - 1 && y == n - 1) {
		ans++;
		return;
	}

	// 현재 가로 or 세로
	if (dr == 0 || dr == 1) {
		if (Straight(x, y, dr))
			DFS(x + dx[dr], y + dy[dr]);
	}
	else {
		for (int i = 0; i < 2; i++) {
			if (Straight(x, y, i)) {
				dr = i;
				DFS(x + dx[dr], y + dy[dr]);
			}
		}
	}

	if (Diagonal(x, y)) {
		dr = 2;
		DFS(x + dx[dr], y + dy[dr]);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		arr[i].resize(n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	DFS(0, 1);

	cout << ans;
}