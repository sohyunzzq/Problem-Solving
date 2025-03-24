/*
[DP]

i >= 4일 때
DP[i] = DP[i-1] + DP[i-2] + DP[i-3]
*/

#include <iostream>
using namespace std;

#define endl '\n'

int DP[11];

int main() {
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	for (int i = 4; i <= 10; i++) {
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
	}

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		cout << DP[n] << endl;
	}
}