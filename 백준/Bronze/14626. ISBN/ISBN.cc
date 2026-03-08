#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	int sum = 0;

	bool odd = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '*') {
			if (i % 2 == 1)
				odd = false;
			continue;
		}

		int num = int(s[i] - '0');

		sum += (i % 2 == 0 ? num : num * 3);
		sum %= 10;
	}

	cout << (odd ? (10 - sum) % 10 : (sum * 3) % 10);
}