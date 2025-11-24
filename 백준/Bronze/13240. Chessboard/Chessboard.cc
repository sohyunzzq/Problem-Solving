#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int x, y;
	cin >> x >> y;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0)
					cout << "*";
				else
					cout << ".";
			}
			else {
				if (j % 2 == 0)
					cout << ".";
				else
					cout << "*";
			}
		}
		cout << endl;
	}
}