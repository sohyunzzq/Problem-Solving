#include <iostream>
using namespace std;

#define endl '\n'

int main() {
	long long P[101] = {};
	P[1] = P[2] = P[3] = 1;

	for (int i = 4; i <= 100; i++) {
		P[i] = P[i - 3] + P[i - 2];
	}

	int t;
	cin >> t;

	for (int tc = 0; tc < t; tc++) {
		int n;
		cin >> n;

		cout << P[n] << endl;
	}
}