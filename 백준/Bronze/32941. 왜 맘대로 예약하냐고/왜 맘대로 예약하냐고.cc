#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t, x;
	cin >> t >> x;

	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;

		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;

			if (a == x)
				cnt++;
		}
	}

	cout << (cnt == n ? "YES" : "NO");
}