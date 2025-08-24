#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s;
	getline(cin, s);

	int len = s.size();
	if (len <= 2)
		cout << "CE";
	else if (s[0] == '"' && s[len - 1] == '"')
		for (int i = 1; i < len - 1; i++)
			cout << s[i];
	else
		cout << "CE";
}