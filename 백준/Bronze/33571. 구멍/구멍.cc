#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int ALPHA[26] = { 1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };
	int alpha[26] = { 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	string s;
	getline(cin, s);

	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			cnt += ALPHA[s[i] - 'A'];
		else if ('a' <= s[i] && s[i] <= 'z')
			cnt += alpha[s[i] - 'a'];
		else if (s[i] == '@')
			cnt++;
	}

	cout << cnt;
}