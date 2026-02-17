#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		char alpha = s[i] - 3;

		if (!isalpha(alpha))
			alpha += 26;

		cout << alpha;
	}
}