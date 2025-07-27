#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(0);

int main() {
	fastio;

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;

		vector<int> arr(n);

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		vector<int> DP(n, 0);
		int ans = arr[0];
		
		for (int i = 0; i < n; i++) {
			DP[i] = arr[i];
			ans = max(ans, DP[i]);

			for (int j = i + 1; j < n; j++) {
				DP[j] = DP[j - 1] + arr[j];
				ans = max(ans, DP[j]);
			}
		}

		cout << ans << endl;
	}
}