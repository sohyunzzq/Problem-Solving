#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	bool correct = true;
	int len = s.length();

	for (int i = 0; i < len / 2; i++) {
		if (s[i] == '|' && s[len - i - 1] == '|')
			continue;

		if (s[i] == '(' && s[len - i - 1] == ')')
			continue;

		correct = false;
	}

	cout << (correct ? "correct" : "fix");
}