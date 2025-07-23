#include <iostream>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(0);

int main() {
	fastio;

	int n;
	cin >> n;

	vector<double> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	double ans = arr[0];
	vector<double> DP(n);
	for (int i = 0; i < n; i++) {
		DP[i] = arr[i];
		ans = max(ans, DP[i]);
		for (int j = i + 1; j < n; j++) {
			DP[j] = DP[j - 1] * arr[j];
			ans = max(ans, DP[j]);
		}
	}

	cout << fixed;
	cout.precision(3);

	cout << ans;
}