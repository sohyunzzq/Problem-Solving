#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	string s;
	getline(cin, s);

	for (int tc = 1; tc <= T; tc++) {
		getline(cin, s);

		int cur = 0;
		int len = s.length();
		int right = len - 1;

		for (int left = 0; left < len; left = cur) {
			while (s[cur] != ' ' && cur < len) {
				cur++;
			}
			
			right = cur - 1;
			cur++;
			
			while (left <= right)
				cout << s[right--];
			cout << " ";

			if (cur >= len)
				break;
		}
		cout << endl;
	}
}