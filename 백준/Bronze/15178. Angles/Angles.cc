#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		cout << a << " " << b << " " << c << " ";

		cout << (a + b + c == 180 ? "Seems OK" : "Check") << endl;
	}
}