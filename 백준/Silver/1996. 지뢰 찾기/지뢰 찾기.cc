#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int n;
int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	vector<vector<char>> arr;
	vector<vector<int>> cnt;
	vector<pair<int, int>> bomb;
	arr.resize(n);
	cnt.resize(n);
	for (int i = 0; i < n; i++) {
		arr[i].resize(n);
		cnt[i].resize(n, 0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			if (arr[i][j] != '.') {
				bomb.push_back({ i, j });
				cnt[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < bomb.size(); i++) {
		int x = bomb[i].first;
		int y = bomb[i].second;
	
		int num = int(arr[x][y] - '0');

		for (int dr = 0; dr < 8; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (InRange(nx, ny) && cnt[nx][ny] != -1) {
				cnt[nx][ny] += num;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cnt[i][j] == -1)
				cout << "*";
			else if (cnt[i][j] >= 10)
				cout << "M";
			else
				cout << cnt[i][j];
		}
		cout << endl;
	}
}