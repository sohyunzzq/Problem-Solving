#include <iostream>
using namespace std;

#define N_SZ 116 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	long long DP[N_SZ + 1];

	DP[1] = DP[2] = DP[3] = 1;

	for (int i = 4; i <= n; i++)
		DP[i] = DP[i - 1] + DP[i - 3];
	cout << DP[n];
}