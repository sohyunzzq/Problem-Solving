#include <iostream>
#include <string>
using namespace std;

int Rev(string s) {
	int res = 0;

	for (int i = s.size() - 1; i >= 0; i--) {
		res += int(s[i] - '0');
		res *= 10;
	}

	return res / 10;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string x, y;
	cin >> x >> y;

	int xx, yy;
	xx = Rev(x);
	yy = Rev(y);

	cout << Rev(to_string(xx + yy));
}