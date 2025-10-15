#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n, c;
		cin >> n >> c;

		int sum = n / c;
		if (n % c)
			sum++;
		cout << sum << endl;
	}
}