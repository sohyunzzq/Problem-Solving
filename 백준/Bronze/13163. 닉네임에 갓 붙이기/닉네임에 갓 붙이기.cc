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

		cout << "god";
		int j = 1;
		while (s[j++] != ' ')
			;

		for (; j < s.size(); j++) {
			if (s[j] == ' ')
				continue;
			cout << s[j];
		}
		cout << endl;
	}
}