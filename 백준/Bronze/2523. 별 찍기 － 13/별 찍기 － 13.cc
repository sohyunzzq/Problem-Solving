#include <iostream>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
	fastio;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
			cout << "*";
		cout << endl;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = n - i - 2; j >= 0; j--)
			cout << "*";
		cout << endl;
	}
}