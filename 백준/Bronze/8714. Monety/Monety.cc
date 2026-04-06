#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	int zero = 0, one = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (a == 0)
			zero++;
		else
			one++;
	}

	cout << min(zero, one);
}