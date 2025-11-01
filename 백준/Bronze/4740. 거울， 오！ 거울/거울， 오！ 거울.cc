#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s;
	while (1) {
		getline(cin, s);

		if (s == "***")
			break;

		for (int i = 0; i < s.size(); i++)
			cout << s[s.size() - i - 1];
		cout << endl;
	}
}