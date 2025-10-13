#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;

		if (a > (n + 1) / 2)
			cout << n;
		else
			cout << 1;
		cout << " ";
	}
}