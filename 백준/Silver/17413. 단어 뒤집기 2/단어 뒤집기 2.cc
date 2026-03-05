#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			while (s[i] != '>')
				cout << s[i++];
			cout << s[i];
		}
		else if (s[i] != ' ') {
			int st = i;
			while (i + 1 < s.size() && s[i + 1] != ' ' && s[i + 1] != '<')
				i++;
			int en = i;

			for (int j = en; j >= st; j--)
				cout << s[j];
		}
		else
			cout << s[i];
	}
}