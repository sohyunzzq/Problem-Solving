#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define N_SZ 45

long long ans[N_SZ];

int main() {
	fastio;

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;

		ans[0] = ans[1] = 1;

		for (int i = 2; i <= n; i++)
			ans[i] = ans[i - 1] + ans[i - 2];

		cout << ans[n] << endl;
	}
}