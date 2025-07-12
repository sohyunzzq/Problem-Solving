#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);

#define N_SZ 31

int main() {
	fastio;

	long long DP[N_SZ][N_SZ];

	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; i++)
		DP[i][0] = DP[i][i] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i / 2; j++)
			DP[i][j] = DP[i][i - j] = DP[i - 1][j - 1] + DP[i - 1][j];

	cout << DP[n - 1][k - 1];
}