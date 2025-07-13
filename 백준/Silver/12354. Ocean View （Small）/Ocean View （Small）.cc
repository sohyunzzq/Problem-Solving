#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
	fastio;

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;

		vector<int> h;
		vector<int> dp;
		h.clear();
		dp.clear();

		h.resize(n);
		dp.resize(n, 1);

		for (int i = 0; i < n; i++)
			cin >> h[i];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (h[i] > h[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		sort(dp.begin(), dp.end());

		cout << "Case #" << tc << ": " << n - dp[n - 1] << endl;
	}
}