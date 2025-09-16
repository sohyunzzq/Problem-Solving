#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	while (1) {
		int a, b, c;
		cin >> a >> b >> c;

		if (!a && !b && !c)
			break;

		if (b - a == c - b)
			cout << "AP " << c + c - b;
		else
			cout << "GP " << c * int(c / b);
		cout << endl;
	}
}