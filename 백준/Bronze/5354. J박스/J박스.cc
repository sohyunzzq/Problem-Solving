#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;

		for (int j = 0; j < n; j++) {
			if (j == 0 || j == n - 1) {
				for (int k = 0; k < n; k++)
					cout << "#";
				cout << endl;
			}
			else {
				cout << "#";
				for (int k = 0; k < n - 2; k++)
					cout << "J";
				cout << "#";
				cout << endl;
			}
		}
		cout << endl;
	}
}