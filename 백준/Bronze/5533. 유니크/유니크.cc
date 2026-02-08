#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> arr;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		arr[i].resize(3);
	}

	vector<vector<int>> check;
	check.resize(3);
	for (int i = 0; i < 3; i++)
		check[i].resize(101, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];

			check[j][arr[i][j]]++;
		}
	}

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			if (check[j][arr[i][j]] == 1)
				sum += arr[i][j];
		}
		cout << sum << endl;
	}
}