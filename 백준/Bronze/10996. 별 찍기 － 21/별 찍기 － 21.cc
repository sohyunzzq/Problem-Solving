#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	for (int row = 0; row < 2 * n; row++) {
		if (row % 2 == 0) {
			for (int i = 0; i < n; i++) {
				if (i % 2 == 0)
					cout << "*";
				else
					cout << " ";
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				if (i % 2 == 0)
					cout << " ";
				else
					cout << "*";
			}
		}
		cout << endl;
	}
}