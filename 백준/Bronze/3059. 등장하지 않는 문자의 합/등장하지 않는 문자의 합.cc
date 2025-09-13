#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;

		bool alpha[26];
		for (int j = 0; j < 26; j++)
			alpha[j] = false;

		for (int j = 0; j < s.size(); j++)
			alpha[s[j] - 'A'] = true;

		int ans = 0;
		for (int j = 0; j < 26; j++)
			if (!alpha[j])
				ans += j + 'A';

		cout << ans << endl;
	}
}