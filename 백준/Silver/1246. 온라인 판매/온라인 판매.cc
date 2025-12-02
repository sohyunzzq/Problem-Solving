#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<long long> price(m);
	for (int i = 0; i < m; i++)
		cin >> price[i];

	sort(price.begin(), price.end());

	int cheap = 0;
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		long long sum = 0;
		int cnt = min(n, m - i);

		if (ans < cnt * price[i]) {
			ans = cnt * price[i];
			cheap = price[i];
		}
		ans = max(ans, cnt * price[i]);
	}

	cout << cheap << " " << ans;
}