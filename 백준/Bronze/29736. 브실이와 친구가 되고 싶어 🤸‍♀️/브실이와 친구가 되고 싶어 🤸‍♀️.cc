#include <iostream>
using namespace std;

int main() {
	int a, b, k, x;
	cin >> a >> b >> k >> x;

	int ans = 0;
	for (int i = max(0, k - x); i <= k + x; i++) {
		if (i < a || i > b)
			continue;
		ans++;
	}

	if (ans == 0)
		cout << "IMPOSSIBLE";
	else
		cout << ans;
}