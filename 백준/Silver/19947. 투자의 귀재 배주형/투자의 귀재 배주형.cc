#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int DP[11];

int main() {
	fastio;

	int h, y;
	cin >> h >> y;

	DP[0] = h;
	DP[1] = 1.05 * DP[0];
	DP[2] = 1.05 * DP[1];
	DP[3] = max(1.05 * DP[2], 1.2 * DP[0]);
	DP[4] = max(1.05 * DP[3], 1.2 * DP[1]);
	
	for (int i = 1; i <= y; i++) {
		DP[i] = max(1.05 * DP[i - 1], 1.2 * DP[i - 3]);
		DP[i] = max(DP[i], int(1.35 * DP[i - 5]));
	}

	cout << DP[y];
}