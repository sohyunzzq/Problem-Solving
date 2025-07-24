#include <iostream>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(0);

#define N_SZ 68

int main() {
	fastio;

	int t;
	cin >> t;

	long long DP[N_SZ];

	DP[0] = DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;
	for (int i = 4; i < N_SZ; i++)
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3] + DP[i - 4];

	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;

		cout << DP[n] << endl;
	}
}