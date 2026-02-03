#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	long long x, y;
	cin >> x >> y;

	long long z = y * 100 / x;

	if (z >= 99)
		cout << -1;
	else {
		int left = 0, right = 1e9;

		while (left <= right) {
			long long mid = (left + right) / 2;
			long long tmp_z = (y + mid) * 100 / (x + mid);

			if (tmp_z > z) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		cout << left;
	}
}