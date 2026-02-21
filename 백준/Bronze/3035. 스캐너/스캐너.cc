#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, r, c;
	cin >> n >> m >> r >> c;

	vector<vector<char>> arr;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		arr[i].resize(m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++) {
		for (int ii = 0; ii < r; ii++) {
			for (int j = 0; j < m; j++) {
				for (int jj = 0; jj < c; jj++)
					cout << arr[i][j];
			}
			cout << endl;
		}
	}
}