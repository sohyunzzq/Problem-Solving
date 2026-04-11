#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int h, m, s;
	cin >> h >> m >> s;

	s++;
	if (s == 60) {
		s = 0;
		m++;
	}
	if (m == 60) {
		m = 0;
		h++;
	}
	if (h == 24)
		h = 0;

	if (h >= 10)
		cout << h;
	else
		cout << 0 << h;
	cout << ":";
	if (m >= 10)
		cout << m;
	else
		cout << 0 << m;
	cout << ":";
	if (s >= 10)
		cout << s;
	else
		cout << 0 << s;
}