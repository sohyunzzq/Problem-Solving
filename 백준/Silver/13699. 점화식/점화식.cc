#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0);

long long DP[36];

int main() {
	fastio;

	DP[0] = 1;
	for (int i = 1; i <= 35; i++) {
		for (int num = 0; num < i / 2; num++) {
			DP[i] += DP[num] * DP[i - num - 1];
		}
		DP[i] *= 2;
		if (i % 2 == 1)
			DP[i] += DP[i / 2] * DP[i / 2];
	}

	int n;
	cin >> n;

	cout << DP[n];
}