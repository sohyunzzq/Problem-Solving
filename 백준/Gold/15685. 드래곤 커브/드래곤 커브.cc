#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_XY 100

bool arr[MAX_XY + 1][MAX_XY + 1];
vector<int> path;

int basic[] = { 0, 1, 2, 1, 2, 3, 2, 1 };
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

void MakePath() {
	int sz = path.size();

	for (int i = 0; i < sz/2; i++)
		path.push_back((path[i] + 2) % 4);
	for (int i = sz / 2; i < sz; i++)
		path.push_back(path[i]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		path.assign(basic, basic + 8);

		int x, y, d, g;
		cin >> x >> y >> d >> g;

		// 4세대 이상일 때 구해주기
		for (int i = 4; i <= g; i++)
			MakePath();

		arr[x][y] = true;
		for (int i = 0; i < pow(2, g); i++) {
			x += dx[(path[i] + d) % 4];
			y += dy[(path[i] + d) % 4];

			arr[x][y] = true;
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < MAX_XY; i++)
		for (int j = 0; j < MAX_XY; j++)
			if (arr[i][j] && arr[i][j + 1] && arr[i + 1][j] && arr[i + 1][j + 1])
				cnt++;

	cout << cnt;
}