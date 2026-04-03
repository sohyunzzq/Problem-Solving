#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	int cur = s.size();

	while (cur) {
		cout << s[s.size() - cur];
		if (cur % 3 == 1 && cur != 1)
			cout << ",";
		cur--;
	}
}