#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

vector<int> dp;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	dp.resize(n + 1);

	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[n] << endl;
	while (n) {
		cout << n << " ";
		if (n % 2 == 0 && dp[n] == dp[n / 2] + 1)
			n /= 2;
		else if (n % 3 == 0 && dp[n] == dp[n / 3] + 1)
			n /= 3;
		else
			n--;
	}
}