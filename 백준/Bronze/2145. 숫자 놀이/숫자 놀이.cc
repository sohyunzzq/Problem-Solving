#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	while (1) {
		int n;
		cin >> n;

		if (!n)
			break;

		int tmp;
		while (1) {
			tmp = 0;
			while (n) {
				tmp += n % 10;
				n /= 10;
			}

			if (tmp < 10)
				break;

			n = tmp;
		}
		cout << tmp << endl;
	}
}