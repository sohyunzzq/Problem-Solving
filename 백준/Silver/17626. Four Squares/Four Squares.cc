#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 50000

int n;
int DP[MAX_N + 1];

int GetDP(int n) {
	if (DP[n] != 5)
		return DP[n];
	
	for (int i = sqrt(n); i >= 1; i--) {
		if (i * i == n)
			DP[n] = 1;
		else 
			DP[n] = min(DP[n], 1 + GetDP(n - i * i));
	}

	return DP[n];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 1; i <= MAX_N; i++)
		DP[i] = 5;

	cout << GetDP(n);
}