#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	string s;
	cin >> n>>s;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'J')
			cout << 'O';
		else if (s[i] == 'O')
			cout << 'I';
		else
			cout << 'J';
	}
}