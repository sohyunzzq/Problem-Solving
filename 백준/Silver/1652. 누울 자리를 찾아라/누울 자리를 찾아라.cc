#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<vector<char>> arr;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		arr[i].resize(n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int row = 0, col = 0;
	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = 1; j < n; j++) {
			if (arr[i][j - 1] == '.' && arr[i][j] == '.' && !flag) {
				row++;
				flag = true;
			}
			else if (arr[i][j] == 'X')
				flag = false;
		}
	}

	for (int j = 0; j < n; j++) {
		bool flag = false;
		for (int i = 1; i < n; i++) {
			if (arr[i - 1][j] == '.' && arr[i][j] == '.' && !flag) {
				col++;
				flag = true;
			}
			else if (arr[i][j] == 'X')
				flag = false;
		}
	}

	cout << row << " " << col;
}