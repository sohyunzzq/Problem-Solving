#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int a, b, c;
		cin >> a >> b >> c;

		cout << a << " " << b << " " << c << endl;

		if (a >= 10 && b >= 10 && c >= 10)
			cout << "triple-double";
		else if ((a >= 10 && b >= 10 && c < 10) ||
			(a < 10 && b >= 10 && c >= 10) ||
			(a >= 10 && b < 10 && c >= 10))
			cout << "double-double";
		else if ((a >= 10 && b < 10 && c < 10) ||
			(a < 10 && b >= 10 && c < 10) ||
			(a < 10 && b < 10 && c >= 10))
			cout << "double";
		else
			cout << "zilch";
		cout << endl << endl;
	}
}