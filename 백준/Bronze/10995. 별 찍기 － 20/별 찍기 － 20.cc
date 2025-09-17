#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++)
				cout << "* ";
			cout << endl;
		}
		else {
			for (int j = 0; j < n; j++)
				cout << " *";
			cout << endl;
		}
	}
}