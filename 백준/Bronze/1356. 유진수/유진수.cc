#include <iostream>
using namespace std;

string s;

bool Check() {
	for (int line = 1; line < s.size(); line++) {
		int left = 1;
		int right = 1;

		for (int i = 0; i < line; i++)
			left *= int(s[i] - '0');

		for (int i = line; i < s.size(); i++)
			right *= int(s[i] - '0');

		if (left == right)
			return true;
	}
	return false;
}

int main() {
	cin >> s;
	cout << (Check() ? "YES" : "NO");
}