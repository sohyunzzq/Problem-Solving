#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> cows(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> cows[i];
	}

	// 누적합 구하기
	vector<vector<int>> sum;
	sum.resize(4);

	for (int i = 1; i <= 3; i++) {
		sum[i].resize(n + 1, 0);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++)
			sum[j][i] = sum[j][i - 1];

		sum[cows[i]][i]++;
	}

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;

		for (int j = 1; j <= 3; j++) {
			cout << sum[j][b] - sum[j][a-1] << " ";
		}
		cout << endl;
	}
}