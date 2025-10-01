#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int x, y;
		cin >> x >> y;

		int idx = 1;

		int left = x;
		int right = y;

		int cnt = 0;
		while (left < right) {
			left += idx;
			cnt++;

			if (left >= right) {
				break;
			}

			right -= idx;
			cnt++;

			if (left >= right) {
				break;
			}

			idx++;
		}
		cout << cnt << endl;
	}
}