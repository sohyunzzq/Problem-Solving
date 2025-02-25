#include <iostream>
using namespace std;

#define SZ 500

int n, m;
int board[SZ][SZ];
int max_val = 0;
int visited[SZ][SZ];

int dx[] = { 0, 1, 0 };
int dy[] = { 1, 0, -1 };

int InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y];
}

void DFS(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		max_val = max(max_val, sum);
		return;
	}

	for (int dr = 0; dr < 3; dr++) {
		int nx = x + dx[dr];
		int ny = y + dy[dr];

		if (CanGo(nx, ny)) {
			visited[nx][ny] = 1;
			DFS(nx, ny, cnt + 1, sum + board[nx][ny]);
			visited[nx][ny] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	// DFS 돌리기
	// ㅜ 모양만 따로 처리하고 나머지는 모든 격자에서 DFS 돌리기

	// 방향을 → ↓으로 제한하려 했는데 그러면 안 만들어지는 모양 생김, 네모도 안 됨
	// 위로만 안 올라가면 되지 않을까?
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			visited[i][j] = 1;
			DFS(i, j, 1, board[i][j]);
			visited[i][j] = 0;
		}

	// ㅜ
	for (int row = 0; row < n - 1; row++)
		for (int col = 0; col < m - 2; col++) {
			int tmp = board[row][col] + board[row][col + 1] + board[row][col + 2] + board[row + 1][col + 1];
			max_val = max(max_val, tmp);
		}

	// ㅗ
	for (int row = 0; row < n - 1; row++)
		for (int col = 0; col < m - 2; col++) {
			int tmp = board[row][col + 1] + board[row + 1][col] + board[row + 1][col + 1] + board[row + 1][col + 2];
			max_val = max(max_val, tmp);
		}

	// ㅏ
	for (int row = 0; row < n - 2; row++)
		for (int col = 0; col < m - 1; col++) {
			int tmp = board[row][col] + board[row + 1][col] + board[row + 2][col] + board[row + 1][col + 1];
			max_val = max(max_val, tmp);
		}

	// ㅓ
	for (int row = 0; row < n - 2; row++)
		for (int col = 0; col < m - 1; col++) {
			int tmp = board[row + 1][col] + board[row][col + 1] + board[row + 1][col + 1] + board[row + 2][col + 1];
			max_val = max(max_val, tmp);
		}

	cout << max_val;
}