#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);

#define N_SZ 1001

int main() {
	fastio;

	int n;
	cin >> n;

	int DP[N_SZ];

	// 상근 승
	DP[1] = DP[3] = 1;

	// 창영 승
	DP[2] = 2;

	for (int i = 4; i <= n; i++)
		// 더 적은 판수를 고르기 위해 min
		DP[i] = min(1 + DP[i - 1], 3 + DP[i - 3]);

	if (DP[n] % 2 == 0)
		cout << "CY";
	else
		cout << "SK";
}