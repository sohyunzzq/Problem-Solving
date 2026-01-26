#include <iostream>
using namespace std;

int a, b, c, d, e, f;

void GetAns() {
	for (int x = -999; x <= 999; x++) {
		for (int y = -999; y <= 999; y++) {
			if (a * x + b * y == c && d * x + e * y == f) {
				cout << x << " " << y;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> a >> b >> c >> d >> e >> f;

	GetAns();
}