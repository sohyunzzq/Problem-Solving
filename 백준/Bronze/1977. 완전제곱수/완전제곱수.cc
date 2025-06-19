#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;

	int sum = 0;
	int min_val = n;

	for (int i = m; i <= n; i++) {
		if (sqrt(i) - int(sqrt(i)) == 0) {
			sum += i;
			min_val = min(min_val, i);
		}
	}
	if (sum != 0)
		cout << sum << " " << min_val;
	else
		cout << -1;
}