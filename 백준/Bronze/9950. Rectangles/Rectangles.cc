#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int a, b, c;
	while (1) {
		cin >> a >> b >> c;

		if (!a && !b && !c)
			break;

		if (!a)
			cout << c / b << " " << b << " " << c;
		else if (!b)
			cout << a << " " << c / a << " " << c;
		else
			cout << a << " " << b << " " << a * b;
		cout << endl;
	}
}