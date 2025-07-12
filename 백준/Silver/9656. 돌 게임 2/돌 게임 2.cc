#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);

#define N_SZ 1001

int main() {
	fastio;

	int n;
	cin >> n;

	int DP[N_SZ];

	DP[1] = 1;
	DP[2] = 0;
	DP[3] = 1;

	for (int i = 4; i <= n; i++)
		DP[i] = min(DP[i - 1], DP[i - 3]) + 1;

	// 창영 짐
	if (DP[n] % 2 == 0)
		cout << "SK";
	else
		cout << "CY";
}