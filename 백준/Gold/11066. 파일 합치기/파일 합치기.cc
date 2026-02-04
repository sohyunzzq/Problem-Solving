#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int n;
vector<int> arr;
vector<vector<int>> sum;
vector<vector<long long>> dp;

#define INF 10'000'000'000

void Init() {
	arr.clear();
	sum.clear();
	dp.clear();
}

long long GetDP(int st, int en) {
	if (st == en)
		return dp[st][en] = 0;

	if (st + 1 == en)
		return dp[st][en] = arr[st] + arr[en];

	if (dp[st][en] != INF)
		return dp[st][en];

	for (int mid = st; mid < en; mid++)
		dp[st][en] = min(dp[st][en], GetDP(st, mid) + GetDP(mid + 1, en) + sum[st][mid] + sum[mid + 1][en]);

	return dp[st][en];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Init();
		cin >> n;

		arr.resize(n);
		sum.resize(n);
		dp.resize(n);
		for (int i = 0; i < n; i++) {
			sum[i].resize(n, 0);
			dp[i].resize(n, INF);
		}

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum[i][i] = arr[i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				sum[i][j] = sum[i][j - 1] + arr[j];
			}
		}

		GetDP(0, n - 1);

		cout << dp[0][n - 1] << endl;
	}
}