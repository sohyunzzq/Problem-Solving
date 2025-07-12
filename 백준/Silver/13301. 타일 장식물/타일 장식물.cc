#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);

#define N_SZ 81

int main() {
	int n;
	cin >> n;

	long long DP[N_SZ];

	DP[1] = 4;
	DP[2] = 6;

	for (int i = 3; i <= n; i++)
		DP[i] = DP[i - 1] + DP[i - 2];

	cout << DP[n];
}