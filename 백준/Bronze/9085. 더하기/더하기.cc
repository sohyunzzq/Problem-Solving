#include <iostream>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
	fastio;

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;

		int ans = 0;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;

			ans += a;
		}
		cout << ans << endl;
	}
}