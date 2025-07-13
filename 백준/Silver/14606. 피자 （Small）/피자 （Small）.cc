#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int DP[11];

int main() {
	fastio;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= i / 2; j++) {
			tmp = j * (i - j);

			tmp += DP[j] + DP[i - j];
		}
		DP[i] = max(DP[i], tmp);
	}

	cout << DP[n];
}