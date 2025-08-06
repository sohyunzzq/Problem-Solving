#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);

		if ('a' <= s[0] && s[0] <= 'z')
			s[0] = s[0] - 'a' + 'A';

		cout << s << endl;
	}
}