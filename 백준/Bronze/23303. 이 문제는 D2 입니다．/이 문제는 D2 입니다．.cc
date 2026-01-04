#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s;
	getline(cin, s);

	bool flag = false;
	for (int i = 0; i < s.size() - 1; i++)
		if ((s[i] == 'd' && s[i + 1] == '2') || (s[i] == 'D' && s[i + 1] == '2'))
			flag = true;

	cout << (flag ? "D2" : "unrated");
}