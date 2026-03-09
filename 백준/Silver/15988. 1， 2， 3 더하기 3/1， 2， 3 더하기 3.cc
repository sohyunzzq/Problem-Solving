#include <iostream>
using namespace std;
#define endl '\n'

#define MAX_N 1'000'000
#define MOD 1'000'000'009

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	long long DP[MAX_N + 1];
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	for (int i = 4; i <= MAX_N; i++)
		DP[i] = (DP[i - 1] + DP[i - 2] + DP[i - 3]) % MOD;

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;

		cout << DP[n] << endl;
	}
}