#include <iostream>
using namespace std;

#define MX_PR 1000

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;

	int set_pr = MX_PR + 5;
	int ea_pr = MX_PR + 5;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		set_pr = min(set_pr, a);
		ea_pr = min(ea_pr, b);
	}

	int ans = 0;
	if (n >= 6 && set_pr < ea_pr * 6) {
		ans += (n / 6) * set_pr;
		n %= 6;
	}

	if (n < 6 && set_pr < ea_pr * n) {
		ans += set_pr;
		n = 0;
	}

	ans += n * ea_pr;

	cout << ans;
}