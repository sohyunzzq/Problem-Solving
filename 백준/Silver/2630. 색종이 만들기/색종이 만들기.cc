#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int n;
vector<vector<int>> paper;
int white = 0;
int blue = 0;

void Chop(int row, int col, int sz) {
	int tmp = 0;

	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
			tmp += paper[row + i][col + j];

	if (tmp == 0)
		white++;
	else if (tmp == sz * sz)
		blue++;
	else {
		sz /= 2;
		Chop(row, col, sz);
		Chop(row, col + sz, sz);
		Chop(row + sz, col, sz);
		Chop(row + sz, col + sz, sz);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	paper.resize(n);
	for (int i = 0; i < n; i++)
		paper[i].resize(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];

	Chop(0, 0, n);

	cout << white << endl << blue;
}