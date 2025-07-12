#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);

#define K_SZ 46

int main() {
	fastio;

	int k;
	cin >> k;

	long long DP[K_SZ];

	DP[0] = 0;
	DP[1] = 1;

	for (int i = 2; i <= k; i++)
		DP[i] = DP[i - 2] + DP[i - 1];

	cout << DP[k - 1] << " " << DP[k];
}