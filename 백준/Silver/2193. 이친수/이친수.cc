#include <iostream>
using namespace std;

#define N_SZ 91

long long DP[N_SZ];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	DP[1] = 1;
	DP[2] = 1;

	for (int i = 3; i <= n; i++)
		DP[i] = DP[i - 2] + DP[i - 1];

	cout << DP[n];
}