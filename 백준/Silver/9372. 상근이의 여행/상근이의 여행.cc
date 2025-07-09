#include <iostream>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
	fastio;

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
		}

		cout << n-1 << endl;
	}
}