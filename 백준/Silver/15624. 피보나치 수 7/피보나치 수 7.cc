#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);

#define N_SZ 1'000'001
#define NUM 1'000'000'007

long long DP[N_SZ];

int main() {
	DP[0] = 0;
	DP[1] = 1;
	for (int i = 2; i < N_SZ; i++)
		DP[i] = (DP[i - 1] + DP[i - 2]) % NUM;

	int n;
	cin >> n;
	
	cout << DP[n];
}