#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		// 각 자릿수가 3 6 9 면 cnt++
		int tmp = i;

		while (tmp != 0) {
			switch (tmp % 10) {
			case 3:
			case 6:
			case 9:
				cnt++;
				break;
			}
			tmp /= 10;
		}
	}

	cout << cnt;
}