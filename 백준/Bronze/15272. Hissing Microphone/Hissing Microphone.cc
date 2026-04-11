#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	bool flag = false;
	for (int i = 0; i < s.size() - 1; i++)
		if (s[i] == 's' && s[i + 1] == 's')
			flag = true;

	cout << (flag ? "hiss" : "no hiss");
}