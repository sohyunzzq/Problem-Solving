#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);

#define N_SZ 100'001

int main() {
	fastio;

	int n;
	cin >> n;

	int DP[N_SZ];
	DP[1] = -1;
	DP[2] = 1;
	DP[3] = -1;
	DP[4] = 2;
	DP[5] = 1;

	for (int i = 6; i <= n; i++) {
		if (DP[i - 2] != -1 && DP[i - 5] != -1)
			DP[i] = min(DP[i - 2], DP[i - 5]) + 1;
		else if (DP[i - 2])
			DP[i] = DP[i - 2] + 1;
		else if (DP[i - 5])
			DP[i] = DP[i - 5] + 1;
		else
			DP[i] = -1;
	}

	cout << DP[n];
}